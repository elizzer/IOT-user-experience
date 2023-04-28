#include <Arduino.h>
#include <string.h>


class htmlPages{
    public:
        static String home();
        static String login(bool);
        static String config();
};