#include<Arduino.h>
#include<EEPROM.h>

struct data{
    String username;
    String password;
    String WifiName;
    String WifiPassword;
    String DeviceName;
    String DevicePassword;
    void prtinData();
};


class DataManager{
        data Data;
    public:
        DataManager();
        void store();
        void read();

        // Getters
        String getUsername();
        String getPassword();
        String getWifiName();
        String getWifiPassword();
        String getDeviceName();
        String getDevicePassword();
        // setters
        String setUsername(String value);
        String setPassword(String value);
        String setWifiName(String value);
        String setWifiPassword(String value);
        String setDeviceName(String value);
        String setDevicePassword(String value);

};