#pragma once

#include <ESP8266WiFi.h>
#include <string>

class ParseClass {

public:
 int RcvCmd;

 void Parse(String * command);
 void SendDataToBlynkServer();
};

