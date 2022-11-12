#include <Arduino.h>
#include "halSensor.h"
#include "tasks.h"

void setup()
{
  Serial.begin(115200);
  
  halSensorInit();
  taskCreate();
}

void loop()
{
  // put your main code here, to run repeatedly:
}