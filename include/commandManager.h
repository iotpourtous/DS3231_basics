#ifndef commandManager_h
#define commandManager_h

#include "ds3231Def.h"

String commands(char *readData)
{
  String retour = "Commande inexistante";
  switch (readData[0])
  {
  case '<':
    if ((readData[1] - '0') == DS3231_SENSOR_ID)
    {
      char subbuff[8];
      memcpy(subbuff, &readData[2], 8);
      retour = "<" + String(DS3231_SENSOR_ID) + rtc.writeCommand(subbuff);
    }
    break;
  case '>':
    if ((readData[1] - '0') == DS3231_SENSOR_ID)
    {
      char subbuff[8];
      memcpy(subbuff, &readData[2], 8);
      retour = ">" + String(DS3231_SENSOR_ID) + rtc.readCommand(DS3231_SENSOR_ID, subbuff);
    }
    break;
  }
  return retour;
}

void commandsFromSerial()
{
  if (Serial.available() > 0)
  {
    char readData[MAX_COMMAND_SIZE];

    size_t bytesReceived = Serial.readBytesUntil('\n', readData, MAX_COMMAND_SIZE);
    if (bytesReceived > 0)
    {
      Serial.println(commands(readData));
    }
  }
}
void commandsFromBT()
{
  if (SerialBT.available() > 0)
  {
    char readData[MAX_COMMAND_SIZE];

    size_t bytesReceived = SerialBT.readBytesUntil('\n', readData, MAX_COMMAND_SIZE);
    if (bytesReceived > 0)
    {
      SerialBT.println(commands(readData));
    }
  }
}

#endif