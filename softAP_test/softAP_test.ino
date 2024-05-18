
/******** WiFi Access Point + Server ********/
/*
Version: v1.0
Author : CodeNwireX
Date   : 22.11.2023

Description:
This code demonstrates how to configure the ESP8266 as both a Wi-Fi client and an Access Point (AP).
It connects to an existing Wi-Fi network and simultaneously sets up an AP with specified credentials.
It also demonstrates how to set up simple web server.

Instructions:
1. Update the 'ssid' and 'password' variables with the credentials of your Wi-Fi network.
2. Customize 'apSsid' and 'apPassword' for the desired Access Point settings.
3. Ensure that your ESP8266 is connected to the appropriate pins and power source.

Important Note:
The ESP8266 can act as a Wi-Fi client and an Access Point simultaneously.
*/

#include<ESP8266WiFi.h>  //include WiFi library 
#include<ESP8266WebServer.h> //for webserver



// //Your Network ssid and password
// const char* ssid = "Your SSID";
// const char* password = "Your Password";

//Your Acess Point ssid and Password
const char* apSsid = "AP SSID";
const char* apPassword = "AP Password";

//Set web server on port 80
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Hello from ESP8266 Server!");
}

void setup() {
  // put your setup code here, to run once:
  //initiate serial communication 
  Serial.begin(115200);

  // //Connect to  WiFi network
  // WiFi.begin(ssid,password);
  // while (WiFi.isConnected() !=1)
  // {
  //   delay(500);
  //   Serial.println("Connecting to WiFi.... please wait.");
  // }
  // Serial.println("Connected to WiFi");
  // Serial.print("LocalIP: ");
  // Serial.println(WiFi.localIP());
  

  Serial.println("Starting Access Point...please wait.");
  delay(1000);
  // Configure Acess Point 
  WiFi.softAP(apSsid,apPassword);
  Serial.println("Access Point is started now.");
  Serial.print("SoftAP IP Address : ");
  Serial.println(WiFi.softAPIP());
  
 // //configure AP
 //IPAddress localIp(192,168,1,1);
 //IPAddress gateway(192,168,1,1);
 //IPAddress subnet(255,255,0,0);

 // WiFi.softAPConfig(localIp,gateway,subnet);
 // Serial.print("SoftAP IP Address : ");
 // Serial.println(WiFi.softAPIP());



  // Route handling
  server.on("/", HTTP_GET, handleRoot);

  // Start server
  server.begin();
  Serial.println("HTTP server started");

}

void loop() {

  server.handleClient();
  server.send(200, "text/plain", "Hey");
  delay(500);
  server.send(300, "text/plain", "Hello");
}
