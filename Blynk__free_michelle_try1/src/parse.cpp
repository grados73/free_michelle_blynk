#include "D:\ESP\Blynk__free_michelle_try1\inc\parse.h"

using namespace std;

void UART_ParseLED();




void ParseClass::Parse(String * command)
{

    String NewComand = *command;

    if(NewComand.indexOf("TEMP")) // TODO! Check "TEMP" or 'TEMP'
    {
        uint8_t PositionOfEqual = NewComand.indexOf('=');
        String STemp = NewComand.substring(PositionOfEqual+1);
        float FTemp = STemp.toFloat();
    }



}

void ParseClass::SendDataToBlynkServer()
{

}

// Parsing testing function to change state of LED
// "LED=1\n"
void UART_ParseLED()
{

}