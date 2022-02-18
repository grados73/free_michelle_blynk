/*************************************************************
* author:    grados73
* project:   free_michelle_blynk
 *************************************************************/

/*************************************************************
 ********* PART OF CODE NEEDED TO BLYNK INIT *****************
 *************************************************************/
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLS6OU4IQQ"
#define BLYNK_DEVICE_NAME           "GRAD Quickstart Device"
#define BLYNK_AUTH_TOKEN            "6-UIFG5EkFyAbtLATzif3RagR20M8ey2"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "D:\ESP\Blynk__free_michelle_try1\inc\parse.h"

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SuperExtraSzybkiInternetZuzy";
char pass[] = "gradowscy6";

WidgetLED led1(V1);

BlynkTimer timer;

#define DEBUGING_MODE 1

// Real - Build In BLUE LED Declaration
#define LED 2

// Variables to Serial comunication
String inputString = "";                 // a String to hold incoming data
String * WskInputString = &inputString;  // Pointer on String holding incoming data
bool stringComplete = false;             // whether the string is complete

// Class with objects and methods to Parse Command from uC
ParseClass UARTuCParse;
// Variable to hold information about last receive command
uint8_t LastCommand;
void SendDataToBlynk(uint8_t CommandID);

void setup()
{
  //  Serial Init
  Serial.begin(115200);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

  //  Initialization of Blynk Cloud access
  Serial.print("BLYNKINITSTART\n");
  Blynk.begin(auth, ssid, pass);
  //TODO! ADD implementation of possibility to change WIFI ssid or pass to connect!
  Serial.print("BLYNKINITSUCCESS\n");
  //  Real - Build In BLUE LED Declaration
  pinMode(LED, OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
  if (stringComplete) {
    // PARSE COMMAND FUNCTION 
    LastCommand = UARTuCParse.Parse(WskInputString);
    SendDataToBlynk(LastCommand);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}


void SendDataToBlynk(uint8_t CommandID)
{
  switch (CommandID)
  {
    case PARSING_TEMPWEW:
      Blynk.virtualWrite(V6, UARTuCParse.TempIns);
      break;
      
    case PARSING_TEMPZEW:
      Blynk.virtualWrite(V7, UARTuCParse.TempOut);
      break;
    
    case PARSING_PRESS:
      Blynk.virtualWrite(V5, UARTuCParse.Press);
      break;
    
    case PARSING_RELAY_ON:
      switch (UARTuCParse.NrOfLastChangedRelay)
      {
        case 1:
          Blynk.virtualWrite(V8, 1);
          break;
        case 2:
          Blynk.virtualWrite(V9, 1);
          break;
        case 3:
          Blynk.virtualWrite(V10, 1);
          break;
        case 4:
          Blynk.virtualWrite(V11, 1);
          break;
        default:
          break;
      }
      break;
    
    case PARSING_RELAY_OFF:
    switch (UARTuCParse.NrOfLastChangedRelay)
      {
        case 1:
          Blynk.virtualWrite(V8, 0);
          break;
        case 2:
          Blynk.virtualWrite(V9, 0);
          break;
        case 3:
          Blynk.virtualWrite(V10, 0);
          break;
        case 4:
          Blynk.virtualWrite(V11, 0);
          break;
        default:
          break;
      }
      break;

    default:
      break;
  }
}
