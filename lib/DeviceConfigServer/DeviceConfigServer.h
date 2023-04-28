#include <ESP8266WebServer.h>
#include <string.h>


struct configStruct{
    String username;
    String userpassword;
    String wifiname;
    String wifipassword;
    String devicename;
    String devicepassword;
    configStruct(){
        String username="";
        String userpassword="";
        String wifiname="";
        String wifipassword="";
        String devicename="admin";
        String devicepassword="admin";
        Serial.println("[+]Struct constructor");
    }

};

class DeviceConfigServer:public ESP8266WebServer{
    static ESP8266WebServer server;
    static bool loggedin;
    static configStruct configData;
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
        static void setConfigData(String username="",String userpassword="",String wifiname="",String wifipassword="",String devicename="",String devicepassword="");
        static void getConfigData();
};
