#ifndef commandManager_h
#define commandManager_h

#include "ds3231Def.h"

String commands(String command)
{
  if (command.substring(0, 2).equals("<" + String(DS3231_SENSOR_ID)))
  {
    return rtc.writeCommand(command.substring(2));
  }
  else if (command.substring(0, 2).equals(">" + String(DS3231_SENSOR_ID)))
  {
    return rtc.readCommand(command.substring(2), DS3231_SENSOR_ID);
  }
  return "Commande inexistante";
}

void commandsFromSerial()
{
  if (Serial.available())
  {
    String command = Serial.readStringUntil('\n');
    Serial.println(commands(command));
  }
}

void commandsFromBT()
{
  if (SerialBT.available() > 0)
  {
      String command = SerialBT.readStringUntil('\n');
      SerialBT.println(commands(command));
  }
}

#endif