#include "AP.h"

bool AP::init(const char* ssid,const char* password, IPAddress localIP ,IPAddress gateway,IPAddress subnet){

  Serial.println("[+]Starting soft AP init...");
  bool config=false;
  bool init=false;
  init=WiFi.softAP(ssid,password);
  Serial.println(init?"Success":"Failed");
  Serial.println("[+]Soft AP config init...");
  config=WiFi.softAPConfig(localIP,gateway,subnet);
  Serial.println(config?"Success":"Failed");
  Serial.println("[+]Ip of the soft AP");
  Serial.print(WiFi.softAPIP());

  if(!init && !config){
    message="AP and config fail";

  }else if(!init && config){
    message="AP fail and config success";
  }else if(init && !config){
    message="AP success and config fail";
  }else{
    message="AP and config success";
  }
  return config && init;
}

String AP::getMessage(){
  return message;
}

bool AP::stop(){
  WiFi.softAPdisconnect();
  return true;
}

void AP::onConnect(){

}