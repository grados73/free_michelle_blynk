/*************************************************************
* author:    grados73
* project:   free_michelle_blynk
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

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SuperExtraSzybkiInternetZuzy";
char pass[] = "gradowscy6";

WidgetLED led1(V1);

BlynkTimer timer;

// Real - Build In BLUE LED Declaration
#define LED 2


void setup()
{
  //  Serial Init
  Serial.begin(115200);

  //  Initialization of Blynk Cloud access
  Blynk.begin(auth, ssid, pass);
  //  Real - Build In BLUE LED Declaration
  pinMode(LED, OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
}
