#include <ESP8266WiFi.h>
#include <string.h>

class AP{
    String message;
    public:
        bool init(const char* ssid,const char* password, IPAddress localIP = IPAddress(192, 168, 0, 1),IPAddress gatway= IPAddress(192, 168, 0, 1),IPAddress subnet= IPAddress(255,255,255,0));
        bool stop();
        void onConnect();
        String getMessage();
};