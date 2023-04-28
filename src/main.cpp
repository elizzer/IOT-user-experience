#include <Arduino.h>

#include <AP.h>
#include <DeviceConfigServer.h>
#include <DataManager.h>

#define SSID "ESPAP"
#define PWD "1234567890"

bool config = false;

AP AccessPoint;
DeviceConfigServer configServer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  DataManager configData;
  // if(!config){
  //   if(AccessPoint.init(SSID,PWD)){
  //   configServer.begin();
  //   }
  // }

  
}


void loop() {
  // put your main code here, to run repeatedly:
  configServer.handleClient();
}
