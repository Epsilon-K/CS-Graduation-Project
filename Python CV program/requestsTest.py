import sys
import requests
import re

URL = "http://lapp.dev:8080"
client = requests.session()

front = client.get(URL+"/login") # sets cookie
csrfToken = re.findall(r'<input type="hidden" name="_token" value="(.*)"', front.text)[0]   # retrieve the CSRF Token
print(csrfToken)

login_data = {"email": "dev.djvan@gmail.com", "password": "Najim5", "remember":'', "_token":csrfToken}

response = client.post(URL + "/login", data=login_data, cookies=client.cookies)
print(response.url)
print(response)
#print(response.text)

###############################  Login Done  ####################################
data = {"title":"Python Request!",
        "body":"Testing the request module to get/post stuff to websites",
        "_token":csrfToken}
p = {"id":25}
r2 = client.post(URL+"/posts", data=data, cookies=client.cookies)
#r2 = client.get(URL+"/posts/show", params=p, cookies=client.cookies)
print(r2.url)
print(r2)
#print(r2.text)
