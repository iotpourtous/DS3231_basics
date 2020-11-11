#include "MyDS3231.h"

char *MyDS3231::dayOfTheWeek()
{
  return _daysOfTheWeek[now().dayOfTheWeek()];
}
void MyDS3231::year(uint16_t year)
{
  Serial.println(year);
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

String MyDS3231::writeCommand(char *readData)
{
  String retour = "Commande inexistante";
  char subbuff[2];
  switch (readData[0])
  {
  case 'Y':
    memcpy(subbuff, &readData[1], 4);
    year(atof(subbuff));
    retour = "T:" + String(now().year());
    break;
  case 'M':
    memcpy(subbuff, &readData[1], 2);
    month(atof(subbuff));
    retour = "T:" + String(now().month());
    break;
  case 'D':
    memcpy(subbuff, &readData[1], 2);
    day(atof(subbuff));
    retour = "T:" + String(now().day());
    break;
  case 'H':
    memcpy(subbuff, &readData[1], 2);
    hour(atof(subbuff));
    retour = "T:" + String(now().hour());
    break;
  case 'm':
    memcpy(subbuff, &readData[1], 2);
    minute(atof(subbuff));
    retour = "T:" + String(now().minute());
    break;
  }
  return retour;
}

String MyDS3231::readCommand(int sensorId, char *readData)
{
  String retour = "Commande inexistante";
  switch (readData[0])
  {
  case 'C':
    retour = "------------------------------------\n";
    retour += "Liste des commandes\n";
    retour += "'>" + String(sensorId) + "C' : Liste des commandes\n";
    retour += "'<" + String(sensorId) + "Y' : modifie l'année\n";
    retour += "'<" + String(sensorId) + "M' : modifie le mois\n";
    retour += "'<" + String(sensorId) + "D' : modifie le jour\n";
    retour += "'<" + String(sensorId) + "H' : modifie l'heure\n";
    retour += "'<" + String(sensorId) + "m' : modifie les minutes\n";
    retour += "'>" + String(sensorId) + "T' : Lit la date et l'heure formatées\n";
    retour += "------------------------------------\n";
    break;
  case 'T':

char formattedFormat[25] = "DD/MM/YYYY hh:mm:ss";
    retour = "T:" + String(now().toString(formattedFormat));
    break;
  }
  return retour;
}