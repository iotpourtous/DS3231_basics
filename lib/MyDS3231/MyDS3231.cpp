#include "MyDS3231.h"

void MyDS3231::begin()
{
  if (!RTC_DS3231::begin())
  {
    throw "Le RTF est introuvable. Vérifier votre câblage";
  }
}
char *MyDS3231::dayOfTheWeek()
{
  return _daysOfTheWeek[now().dayOfTheWeek()];
}
void MyDS3231::year(uint16_t year)
{
  adjust(DateTime(year, now().month(), now().day(), now().hour(), now().minute(), now().second()));
}
void MyDS3231::month(uint16_t month)
{
  adjust(DateTime(now().year(), month, now().day(), now().hour(), now().minute(), now().second()));
}
void MyDS3231::day(uint16_t day)
{
  adjust(DateTime(now().year(), now().month(), day, now().hour(), now().minute(), now().second()));
}
void MyDS3231::hour(uint16_t hour)
{
  adjust(DateTime(now().year(), now().month(), now().day(), hour, now().minute(), now().second()));
}
void MyDS3231::minute(uint16_t minute)
{
  adjust(DateTime(now().year(), now().month(), now().day(), now().hour(), minute, now().second()));
}
void MyDS3231::second(uint16_t second)
{
  adjust(DateTime(now().year(), now().month(), now().day(), now().hour(), now().minute(), second));
}

void MyDS3231::writeCommand(int sensorId, char *readData)
{
  char subbuff[2];
  switch (readData[0])
  {
  case 'Y':
    memcpy(subbuff, &readData[1], 4);
    year(atof(subbuff));
    cout << ">" << sensorId << "T:" << formattedDate() << endl;
    break;
  case 'M':
    memcpy(subbuff, &readData[1], 2);
    month(atof(subbuff));
    cout << ">" << sensorId << "T:" << formattedDate() << endl;
    break;
  case 'D':
    memcpy(subbuff, &readData[1], 2);
    day(atof(subbuff));
    cout << ">" << sensorId << "T:" << formattedDate() << endl;
    break;
  case 'H':
    memcpy(subbuff, &readData[1], 2);
    hour(atof(subbuff));
    cout << ">" << sensorId << "T:" << formattedDate() << endl;
    break;
  case 'm':
    memcpy(subbuff, &readData[1], 2);
    minute(atof(subbuff));
    cout << ">" << sensorId << "T:" << formattedDate() << endl;
    break;
  default:
    throw "Commande inexistante";
    break;
  }
}

void MyDS3231::readCommand(int sensorId, char *readData)
{
  switch (readData[0])
  {
  case 'C':
    cout << "------------------------------------" << endl
         << "Liste des commandes" << endl
         << "'>" << sensorId << "C' : Liste des commandes" << endl
         << "'<" << sensorId << "Y' : modifie l'année" << endl
         << "'<" << sensorId << "M' : modifie le mois" << endl
         << "'<" << sensorId << "D' : modifie le jour" << endl
         << "'<" << sensorId << "H' : modifie l'heure" << endl
         << "'<" << sensorId << "m' : modifie les minutes" << endl
         << "'>" << sensorId << "T' : Lit la date et l'heure formatées" << endl
         << "------------------------------------" << endl;
    break;
  case 'T':
    cout << ">" << sensorId << "T:" << formattedDate() << endl;
    break;
  default:
    throw "Commande inexistante";
    break;
  }
}