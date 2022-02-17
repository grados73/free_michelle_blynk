#pragma once

#include <ESP8266WiFi.h>

class ParseClass {

public:
 int RcvCmd;

 void Parse(String command);
};

