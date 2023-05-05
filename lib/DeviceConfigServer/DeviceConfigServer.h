#ifndef DEVICECONFIGSERVER_H
#define DEVICECONFIGSERVER_H

#include <ESP8266WebServer.h>
#include <string.h>
#include <DataManager.h>

class DeviceConfigServer:public ESP8266WebServer{
    static ESP8266WebServer server;
    static bool loggedin;
    static DataManager configdata;
    // static configStruct configData;
    public:
        // DeviceConfigServer():ESP8266WebServer(80){
        //     Serial.println("[+]DeviceCondifServer init...");
        // }
        DeviceConfigServer();
        static void begin();
        static void handleClient();
        static void home();
        static void login();
        static void loginGet();
        static void config();
        static void configPost();
};

#endif