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
      data = {"CamId":self.ClientCamID, "up":self.up, "down":self.down}
      response = client.post(SERVER_URL + "/updateCam", data=data, cookies=client.cookies)
      if response.status_code == 200:
          print ('Post Successfully :  {up:'+up+', down:'+down+'}')
      else:
          print ("Network Error : " + response.status_code)
