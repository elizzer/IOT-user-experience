#include "DeviceConfigServer.h"
#include <DataManager.h>
#include <htmlPages.h>
// Define the static variable server with an initial value of 80
ESP8266WebServer DeviceConfigServer::server(80);

// Constructor
DeviceConfigServer::DeviceConfigServer():ESP8266WebServer(80){
    Serial.println("[+]DeviceConfigServer init...");
}

bool DeviceConfigServer::loggedin=false;
configStruct DeviceConfigServer::configData;

// Static member function to start the server
void DeviceConfigServer::begin() {
    setConfigData("","","","","admin","admin");
    server.on("/",home);
    server.on("/login",HTTP_GET,loginGet);
    server.on("/login",HTTP_POST,login);
    server.on("/config",HTTP_GET,config);
    server.on("/config",HTTP_POST,configPost);
    server.begin();
    Serial.println("[+]DeviceConfigServer started...");
}

// Static member function to handle client requests
void DeviceConfigServer::handleClient() {
    server.handleClient();
}

void DeviceConfigServer::setConfigData(String username,String userpassword,String wifiname,String wifipassword,String devicename,String devicepassword){
            configData.username=username;
            configData.userpassword=userpassword;
            configData.wifiname=wifiname;
            configData.wifipassword=wifipassword;
            configData.devicename=devicename;
            configData.devicepassword=devicepassword;
}

// Static member function to serve the home page
void DeviceConfigServer::home() {
    server.send(200, "text/html", htmlPages::home().c_str());
}

void DeviceConfigServer::login(){
    Serial.println("[+]Login request received...");
    String username= server.arg(0);
    Serial.println(username.c_str());
    String password= server.arg(1);
    Serial.println(password.c_str());

    Serial.println(DeviceConfigServer::configData.devicename.c_str());

    if(!strcmp(username.c_str(),DeviceConfigServer::configData.devicename.c_str())&&!strcmp(password.c_str(),DeviceConfigServer::configData.devicepassword.c_str())){
        Serial.println("[+]Good credentials...");
        DeviceConfigServer::loggedin=true;
        server.send(200,"text/html",htmlPages::config().c_str());
    }else{
        Serial.println("[+]bad credentials...");
        DeviceConfigServer::loggedin=false;
        server.send(200,"text/html",htmlPages::login(true).c_str());
    }
}

void DeviceConfigServer::loginGet(){
    server.send(200,"text/html",htmlPages::login(false).c_str());
}

void DeviceConfigServer::config(){
    if(!DeviceConfigServer::loggedin){
        server.send(200,"text/html",htmlPages::login(false).c_str());
    }
    else{
        server.send(200,"text/html",htmlPages::config().c_str());
    }
}

void DeviceConfigServer::configPost(){

    String username=server.arg(0);
    String userpassword=server.arg(1);
    String wifiname=server.arg(2);
    String wifipassword=server.arg(3);
    String devicename=server.arg(4);
    String devicepassword=server.arg(5);

    DataManager configData;

    Serial.println(username.c_str());
    Serial.println(userpassword.c_str());
    Serial.println(wifipassword.c_str());
    Serial.println(wifiname.c_str());
    Serial.println(devicename.c_str());
    Serial.println(devicepassword.c_str());

    // configData.Data.DeviceName=devicename
    
    // if(!strcpy(username.c_str()," ")){
        
    // }

}



