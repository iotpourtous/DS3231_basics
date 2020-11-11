#include <Arduino.h>

#include "ds3231Var.h"
#include "commandManager.h"

void setup()
{
    Serial.begin(115200);

    if (!rtc.begin())
    {
        Serial.println("Le RTF est introuvable. Vérifier votre câblage");
    }

    if (rtc.lostPower())
    {
        Serial.println("RTC lost power, let's set the time!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop()
{
    commandsFromSerial();
    commandsFromBT();
    DateTime now = rtc.now();
    char buf1[] = "DD/MM/YYYY hh:mm:ss";
    Serial.println(String(rtc.dayOfTheWeek()) + " " + now.toString(buf1));
    Serial.println(now.toString(zaza));

    char buf4[] = "MM-DD-YYYY";
    Serial.println(now.toString(buf4));
    char buf2[] = "YYMMDD-hh:mm:ss";
    Serial.println(now.toString(buf2));
    delay(2000);
}