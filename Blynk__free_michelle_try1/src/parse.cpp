#include "D:\ESP\Blynk__free_michelle_try1\inc\parse.h"

using namespace std;

void UART_ParseLED();

void ParseClass::Parse(String * command)
{

    String NewComand = *command;

    //Information about current Temperature inside tank
    //TEMPINS=25.5
    if(NewComand.indexOf("TEMPINS") >= 0) // TODO! Check "TEMP" or 'TEMP'
    {
        uint8_t PositionOfEqual = NewComand.indexOf("=");
        if (PositionOfEqual >= 0) // If Equal sign exist 
        {
            String STempI = NewComand.substring(PositionOfEqual+1);
            float FTempI = STempI.toFloat();
            FTempI = FTempI; //To delete warning
        }
    }
    //Information about current Temperature outside the tank
    //TEMPINS=25.5
    else if(NewComand.indexOf("TEMPOUT") >= 0) 
    {
        uint8_t PositionOfEqual = NewComand.indexOf("=");
        if (PositionOfEqual >= 0) // If Equal sign exist 
        {
            String STempO = NewComand.substring(PositionOfEqual+1);
            float FTempO = STempO.toFloat();
            FTempO = FTempO; //To delete warning
        }
    }
    //Information about current Pressure
    //PRES=1014.5
    else if(NewComand.indexOf("PRES") >= 0)
    {
        uint8_t PositionOfEqual = NewComand.indexOf("=");
        if (PositionOfEqual >= 0) // If Equal sign exist 
        {
            String SPres = NewComand.substring(PositionOfEqual+1);
            float FPres = SPres.toFloat();
            FPres = FPres; //To delete warning
        }
    }
    //Command to Turn Relay ON
    //RELAYON=1
    else if(NewComand.indexOf("RELAYON") >= 0)
    {
        uint8_t PositionOfEqual = NewComand.indexOf("=");
        if (PositionOfEqual >= 0) // If Equal sign exist 
        {
            String SRelayNr = NewComand.substring(PositionOfEqual+1);
            uint8_t FRelayNr = SRelayNr.toFloat();
            FRelayNr = FRelayNr; //To delete warning
        }
    }
    //Command to Turn Relay OFF
    //RELAYOFF=1
    else if(NewComand.indexOf("RELAYOFF") >= 0)
    {
        uint8_t PositionOfEqual = NewComand.indexOf("=");
        if (PositionOfEqual >= 0) // If Equal sign exist 
        {
            String SRelayNr = NewComand.substring(PositionOfEqual+1);
            uint8_t FRelayNr = SRelayNr.toFloat();
            FRelayNr = FRelayNr; //To delete warning
        }
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