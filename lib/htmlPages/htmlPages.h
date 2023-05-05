#ifndef HTMLPAGES_H
#define HTMLPAGES_H

#include <Arduino.h>
#include <string.h>


class htmlPages{
    public:
        static String home();
        static String login(bool);
        static String config();
};

#endif