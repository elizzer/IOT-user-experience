#ifndef STATION_H
#define STATION_H

#include<ESP8266WiFi.h>
#include<DataManager.h>

class Station{
    /* Read from eeprom and try connecting to the wifi in there*/
    public:
        static bool Connect();

};

#endif