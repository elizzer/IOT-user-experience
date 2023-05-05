#include "Station.h"

DataManager configData;


bool Station::Connect(){
    Serial.println("[+]Wifi station init...");
    configData.read();
    WiFi.mode(WIFI_STA);
    int temp=20;
    WiFi.begin(configData.getWifiName().c_str(),configData.getWifiPassword().c_str());
    // WiFi.begin("SHADOW 0026","shadow11");
    while (WiFi.status() != WL_CONNECTED && temp>0) {
        delay(500);
        Serial.print(".");
        temp--;
    }
    if(WiFi.status()==WL_CONNECTED){
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
        return true;
    }
    else{
        return false;
    }
    return false;
}