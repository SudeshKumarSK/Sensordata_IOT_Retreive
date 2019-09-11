import pyrebase
from firebase import firebase
import json
config = {
    "apiKey": "AIzaSyDp1SIwC7dKVJJeYxnWwhnvN2CK6W2H8Yc",
    "authDomain": "rpibasic.firebaseapp.com",
    "databaseURL": "https://rpibasic.firebaseio.com",
    "projectId": "rpibasic",
    "storageBucket":  "rpibasic.appspot.com",
    "messagingSenderId":"883647310066"
  }
j = 0
i = 0
a = []

firebase1 = firebase.FirebaseApplication("https://rpibasic.firebaseio.com") 
firebase = pyrebase.initialize_app(config)

db = firebase.database()

#db.child("").child("name").update({"name":"saiharshith is leader"}) #this line will update even the child name
while(1):
    i = i +1
    j = 0
    for j in range(600):
        print(f"count = {j}")

    temp = firebase1.get('/DISTANCE',None)
    text_file = open(f"Distance{i}.txt", "w")
    text_file.write(f"DISTANCE is : {temp}")
    text_file.close()
    print(temp)

