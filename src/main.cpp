#include <Arduino.h>

#include "ds3231Var.h"
#include "commandManager.h"

void setup()
{
    Serial.begin(115200);

    try
    {
        rtc.begin();
    }
    catch (const char *msg)
    {
        cerr << "Une erreur est survenue : " << msg << endl;
        abort();
    }

    if (rtc.lostPower())
    {
        cout << "RTC lost power, let's set the time!" << endl;
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop()
{
    commands();
    cout << rtc.dayOfTheWeek() << ' ' << rtc.formattedDate() << endl;
    delay(2000);
}