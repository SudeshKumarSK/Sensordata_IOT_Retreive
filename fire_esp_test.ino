#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include<SD.h>
#include<NewPing.h>

int trig1 = 5;
int echo1 = 16;

float maxi= 400;
float u1;

NewPing sonar(trig1,echo1,maxi);


#define FIREBASE_HOST "rpibasic.firebaseio.com"  //should not have http:// and the end /
#define FIREBASE_AUTH "X9ZCyDhzZQBl6SfzK56XC8D3XQRGNHtJysDzY0v2"  // go to settings in firebase,select project settings and service account, secrets auth key
#define WIFI_SSID "Sudesh"
#define WIFI_PASSWORD "9176750174"

//Define Firebase Data object
FirebaseData firebaseData;




void setup()
{

  Serial.begin(115200);
  
//##############################CONNECTING TO WIFI USING "WiFi.begin(WIFI_SSID, WIFI_PASSWORD)"###############################

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");//PRINTING THE IP OF CONNECTED NETWORK
  Serial.println(WiFi.localIP());
  Serial.println();

  
//############################CONNECTING TO FIREBASE USING " Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH)"#####################

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
}

void loop()
{
  u1 = sonar.ping_cm();
Firebase.pushFloat(firebaseData, "/DISTANCE", u1);// posting distance
delay(10000);// Stopping the firebase update for few seconds using delay()

Firebase.deleteNode(firebaseData, "/DISTANCE");//deleting the node after 10 seconds

}
