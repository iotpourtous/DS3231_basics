#ifndef myDS3231_h
#define myDS3231_h

#include <iostream>
#include <exception>

#include <RTClib.h>

using namespace std;

class MyDS3231 : public RTC_DS3231
{
private:
    char _daysOfTheWeek[7][12] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "jeudi", "Vendredi", "Samedi"};

public:
    char *dayOfTheWeek();
    void year(uint16_t year);
    void month(uint16_t month);
    void day(uint16_t day);
    void hour(uint16_t hour);
    void minute(uint16_t minute);
    void second(uint16_t second);
    /*
    char *formattedDate()
    {

    DateTime zaza = now();
    Serial.println(zaza.year(), DEC);
    Serial.println(F(zaza.toString(_formattedFormat)));
        return zaza.toString(_formattedFormat);
    }
*/
    String readCommand(int sensorId, char *readData);
    String writeCommand(char *readData);
};

extern MyDS3231 myDS3231;

#endif