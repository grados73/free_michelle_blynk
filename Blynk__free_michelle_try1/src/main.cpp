/*************************************************************

  Blynk using a LED widget on your phone!

  App project setup:
    LED widget on V1
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

// Real LED Definition
#define LED 2


// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    digitalWrite(LED, LOW);
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    digitalWrite(LED, HIGH);
    Serial.println("LED on V1: on");
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(LED, OUTPUT);
  
  timer.setInterval(1000L, blinkLedWidget);

  
}

void loop()
{
  Blynk.run();
  timer.run();
}
