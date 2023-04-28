#include<DataManager.h>

DataManager::DataManager(){
    Serial.println("[+]Data manager init...");
    Data.DeviceName="Device1";
    Data.DevicePassword="Device1";
    Data.WifiName="wifi";
    Data.WifiPassword="wifi";
    Data.username="admin";
    Data.password="admin";
    
    data EData;

    EEPROM.begin(512);
    EEPROM.put(0,Data);
    EEPROM.get(0,EData);
    EData.prtinData();

    Serial.println("[+]Data Manager init success...");

}

void data::prtinData(){
    Serial.println("");
    Serial.println("[+]Printing Config Data:");
    Serial.print("username: ");
    Serial.println(username);
    Serial.print("password: ");
    Serial.println(password);
    Serial.print("WifiName");
    Serial.println(WifiName);
    Serial.print("WifiPassword");
    Serial.println(WifiPassword);
    Serial.print("DeviceName");
    Serial.println(DeviceName);
    Serial.print("DevicePassword");
    Serial.println(DevicePassword);
}


void DataManager::read(){

}

void DataManager::store(){

}

String DataManager::getUsername(){
    return Data.username;
}

String DataManager::getPassword(){
    return Data.password;
}

String DataManager::getWifiName(){
    return Data.WifiName;
}
String DataManager::getWifiPassword(){
    return Data.WifiPassword;
}
String DataManager::getDeviceName(){
    return Data.DeviceName;
}
String DataManager::getDevicePassword(){
    return Data.DevicePassword;
}

String DataManager::setUsername(String value){
    Data.username=value;
    return getUsername();
}
String DataManager::setPassword(String value){
    Data.password=value;
    return getPassword();
}
String DataManager::setWifiName(String value){
    Data.WifiName=value;
    return getWifiName();
}
String DataManager::setWifiPassword(String value){
    Data.WifiPassword=value;
    return getWifiPassword();
}
String DataManager::setDeviceName(String value){
    Data.DeviceName=value;
    return getDeviceName();
}
String DataManager::setDevicePassword(String value){
    Data.DevicePassword=value;
    return getDevicePassword();
}