import numpy as np
import cv2
import random
import string
import re
from datetime import datetime

import threading
import requests
import sys

# - Networking
SERVER_URL = "https://httpbin.org"
ClientCamID = 1 # this needs to be configured
client = requests.session()

class myThread (threading.Thread):
   def __init__(self, up, down):
      threading.Thread.__init__(self)
      self.up = up
      self.down = down
   def run(self):
      data = {"CamId":ClientCamID, "up":self.up, "down":self.down}
      response = client.post(SERVER_URL + "/post", data=data, cookies=client.cookies)
      if response.status_code == 200:
          print ('Post Successfully :  {up:'+str(self.up)+', down:'+str(self.down)+'}')
      else:
          print ("Network Error : " + str(response.status_code))

#-------------------------------- Network

  # Config Vars --------------------------------------------
# - Recognotion
videoFileName = "test.mp4"
cameraDevice = 1
roiWidth = (200,1280)
roiHeight = (400,500)
updatePeriod = 20   #seconds to update the server
updating = False


def abs(a):
    return a if a >= 0 else a*-1

def randomString(stringLength=3):
    letters = string.ascii_uppercase
    return ''.join(random.choice(letters) for i in range(stringLength))


class Vehicle:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.w = 0
        self.h = 0
        self.cx = 0
        self.cy = 0
        self.state = "new"          # new:just fonund       matched:matched to previous frame       unmatched:....
        self.direction = 'up' # or down
        self.model = randomString() # unimplemented, needs training with some ML method to recognize model of the vehicle
        self.ptsHistory = []    # centroid points history
        self.contains = 1          # as a blob by default it contains 1 vehicle    this could become more incase of two vehicles becoming one big blob
        self.dirChanged = False

    def distToOther(self, other):
        return abs(self.cx - other.cx) + abs(self.cy - other.cy) + ((abs(self.w - other.w) + abs(self.h - other.h))/2)


# recives a Vehicle object and a list of Vechicles
# and returns the closest object from ls to v, based on v.cx and v.cy   [center points]
def getClosest(v, ls, stat):
    closest = ls[0]     # It's OKAY! ls is never empty here!
    for ov in ls:
        if ov.state == stat and closest.state != stat : closest = ov
        if v.distToOther(ov) < v.distToOther(closest) and ov.state == stat : closest = ov
    return closest

def countClosest(v, ls, stat, thresh):
    sum = 0
    for ov in ls:
        if ov.state == stat and v != ov and v.distToOther(ov) < thresh:
            sum += 1
    return sum

def getNamesOfVehicles(ls):
    str = ""
    for v in ls: str += v.model + " "
    return str

def setDirection(v):
    dirChangeThr = 5
    global totalCarsCount
    global downCarsCount
    global upCarsCount
    sum = 0
    for i in range(0, len(v.ptsHistory)-1, 1):
        sum += v.ptsHistory[i][1] - v.ptsHistory[i+1][1]

    newDir = "up" if sum >= 0 else "down"
    if v.direction != newDir:
        if v.direction == "up" and v.y < roiHeight[0]+dirChangeThr:
            #hmm, for now total++ and change the name
            totalCarsCount += 1
            upCarsCount += 1
            v.model = randomString()
            v.dirChanged = True
        else:
            if v.direction == "down" and v.y + v.h > roiHeight[1]-dirChangeThr:
                totalCarsCount += 1
                downCarsCount += 1
                v.model = randomString()
                v.dirChanged = True

        v.direction = newDir

def isCloseToEdge(v, thresh=25):
    if v.y < roiHeight[0] + thresh or v.y + v.h > roiHeight[1] - thresh :
        return True
    else : return False

cap = cv2.VideoCapture(videoFileName)
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('last run.mp4', fourcc, 25.0, (1280,720))

ret, frame = cap.read()
dark = frame
fgbg = cv2.createBackgroundSubtractorMOG2()

# ------- Analasys Variables :
Vehicles = []
newVehicles = []
totalCarsCount = 0
upCarsCount = 0
downCarsCount = 0
#------

while ret:
    #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    dark[0:720, 0:1280] = ([0,0,0])     #fills the region with black color [0,0,0]
    blurred = cv2.GaussianBlur(frame, (35,35), 0)   #Blurred version of the frame
    darkBlurred = cv2.addWeighted(blurred, 0.3, dark, 0.7, 0)   #Mixed effect of blurr and tinted black
    cv2.rectangle(darkBlurred, (roiWidth[0],roiHeight[0]), (roiWidth[1],roiHeight[1]), (0,255,200), 2)    #drawing a green Rect
    roi = frame[roiHeight[0]:roiHeight[1], roiWidth[0]:roiWidth[1]]                                       # Region Of Interest
    darkBlurred[roiHeight[0]:roiHeight[1], roiWidth[0]:roiWidth[1]] = roi


    carMask = fgbg.apply(roi)               #Masking The Movement in ROI
    bgrMask = cv2.cvtColor(carMask, cv2.COLOR_GRAY2BGR)
    darkBlurred[roiHeight[1]+10:roiHeight[1]+10 + (roiHeight[1]-roiHeight[0]), roiWidth[0]:roiWidth[1]] = bgrMask

    # -----  Blob Detection  -------
    contours, _ = cv2.findContours(carMask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

    newVehicles.clear()

    # ------- Create Vehicles
    for c in contours :
        rect = cv2.boundingRect(c)
        x,y,w,h = rect
        if w < 50 or h < 50: continue   # too small, probably a Pedestrian
        if w > 450 or h > 120: continue  # too big, probably the first frame [which is just black then suddenly an image appears]
        #--------------------

        x += roiWidth[0]
        y += roiHeight[0]

        # ---- Initial Info
        obj = Vehicle()
        obj.x = x
        obj.y = y
        obj.w = w
        obj.h = h
        obj.cx = obj.x + (obj.w/2)
        obj.cy = obj.y + (obj.h/2)
        if obj.cy <= ((roiHeight[0]+roiHeight[1])/2):
            obj.direction = "down"
        else: obj.direction = "up"

        #Append
        newVehicles.append(obj)

    # Clear blobs inside other blobs
    for v1 in reversed(newVehicles) :
        for v2 in reversed(newVehicles):
            if v2.y > v1.y and v2.y + v2.h < v1.y + v1.h :
                newVehicles.remove(v2)

    # compare newVehicles with Vehicles, this is the tracking code
    trackingThreshold = 35

    #but first...
    for v in Vehicles:
        v.state = "unmatched"   # so that i can tell which vehicle have gone out of frame

    for v in newVehicles:
        if len(Vehicles) < 1:
            v.ptsHistory.append((v.cx, v.cy))
            v.state = "new"
            Vehicles.append(v)
        else:
            # is this v new or was it in an old frame???
                # get the closest v from Vehicles
                # and compare it's distance
                # if it's close enough then assume it is the same
                # Else it's NEW
            closest = getClosest(v, Vehicles, "unmatched")
            if v.distToOther(closest) < trackingThreshold :
                # same same!
                v.state = "matched"
                v.model = closest.model
                v.direction = closest.direction
                v.dirChanged = closest.dirChanged
                v.ptsHistory = closest.ptsHistory
                v.ptsHistory.append((v.cx, v.cy))
                v.contains = closest.contains
                if len(v.ptsHistory) > 10 : v.ptsHistory.pop(0)
                Vehicles.remove(closest)
                setDirection(v)
                Vehicles.append(v)
            else:
                # could be a new one...     [a new vehicle coming from the sides of the frame]
                # hmmm.....
                v.ptsHistory.append((v.cx, v.cy))
                v.state = "new"
                Vehicles.append(v)


    # ----------  Handling unmatched blobs  -----------------
    # could be the result of two intersecting blobs becoming one big blob
        # in which case there should be two "unmatched" blobs and one big "new" blob
    # or the result of a blob that is seperated into two
        # in which case there should be a big "unmatched" blob at intersectionThreshold distance from v
    # or just going out of frame 'ROI'
    intersectionThreshold = 130
    i = 0
    while i < len(Vehicles):
        v = Vehicles[i]
        if v.state == "unmatched" :
            # intersection or seperation ???
            closest = getClosest(v, Vehicles, "new")
            newCount = 0
            for vv in Vehicles:
                if vv.state == "new" : newCount += 1
            if v.distToOther(closest) < intersectionThreshold and closest.state == "new":
                if newCount == 2:       # seperation
                    if v.dirChanged == True and isCloseToEdge(v, 25):
                        totalCarsCount -= 1
                        if v.direction == "up":
                            upCarsCount -= 1
                        else: downCarsCount -= 1
                if newCount == 1 and countClosest(v, Vehicles, "unmatched", intersectionThreshold) == 2:   # intersection, however there should be 2 close "unmatched"
                    if closest.dirChanged != True and v.dirChanged == True: closest.dirChanged = True
                    #closest.contains += v.contains
                    closest.contains = 2
                    pass
            else:
                if isCloseToEdge(v,10):    # out of frame
                    totalCarsCount += v.contains
                    if v.direction == "up": upCarsCount += v.contains
                    else: downCarsCount += v.contains
            Vehicles.remove(v)
            i -= 1
        i += 1

    # ------ Draw
    for v in Vehicles:
        cv2.rectangle(darkBlurred,(v.x,v.y),(v.x+v.w,v.y+v.h),(255,150,0),2)
        cv2.putText(darkBlurred, v.model + " " + v.direction, (v.x+v.w+10,v.y+v.h),0,0.5,(210,255,240))
        cv2.putText(darkBlurred, "Contains " + str(v.contains), (v.x,v.y-3),0,0.5,(210,255,240))
        cv2.putText(darkBlurred, " State: " + v.state, (v.x+v.w-10,v.y-3),0,0.5,(210,255,240))
        # draw history points
        for pt in v.ptsHistory:
            cv2.circle(darkBlurred, (int(pt[0]), int(pt[1])), 2, (255,150,0), 2)



    currSec = int(datetime.now().strftime('%S'))
    if currSec % 5 == 0:   # Every 20 seconds
        if updating != True:
            #print('Update Server!!!' + str(currSec))
            print(SERVER_URL)
            thread = myThread(upCarsCount, downCarsCount)
            thread.start()
            updating = True
    else: updating = False

    cv2.putText(darkBlurred, 'Detected Objects : ' + str(len(newVehicles)) + "  [ "  + getNamesOfVehicles(newVehicles) + "]", (10,30), 2, 0.7, (0,255,0))
    cv2.putText(darkBlurred, 'Current Vehicles : ' + str(len(Vehicles)) + "  [ "  + getNamesOfVehicles(Vehicles) + "]", (10,60), 2, 0.7, (0,255,0))
    cv2.putText(darkBlurred, 'Total Count : ' + str(totalCarsCount), (10,90), 2, 0.7, (0,255,0))
    cv2.putText(darkBlurred, 'Down Count : ' + str(downCarsCount), (roiWidth[0]+5,roiHeight[0]-10), 2, 0.7, (0,255,0))
    cv2.putText(darkBlurred, 'Up Count: ' + str(upCarsCount), (roiWidth[1]-170,roiHeight[0]-10), 2, 0.7, (0,255,0))

    out.write(darkBlurred)
    cv2.imshow('Stream feed', darkBlurred)

    ret, frame = cap.read()
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
out.release()
cv2.destroyAllWindows()
