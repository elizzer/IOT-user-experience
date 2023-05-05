#include <Arduino.h>

#include <AP.h>
#include <DeviceConfigServer.h>
#include <DataManager.h>
#include <Station.h>

#define SSID "ESPAP"
#define PWD "1234567890"

DeviceConfigServer configServer;

void setup() {
  bool config = true;
start:

  // put your setup code here, to run once:
  Serial.begin(115200);

  DataManager configData;
  configData.read();
  
  if(!config){
    Serial.println("[+]Accesspoint mode init...");
    AP AccessPoint;
    if(AccessPoint.init(SSID,PWD)){
      configServer.begin();
      Serial.println("[+]Server config and ready...");
    }
  }
  else{
    Serial.println("[+]Station mode init...");
    Station sta;
    if(!sta.Connect()){
        Serial.println("[+]Wifi connection failed...");
        config=false;
        goto start;
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  configServer.handleClient();
}


//To-Do
/*
  create an intrupt to switch to AP mode.
  also create an intrupt to factory reset the device.
  make LED glow in different pattern in different mode the device is in.
  study wear and tear eeprom and code accordingly.

  clean-code
    make eeprom read only once
*/