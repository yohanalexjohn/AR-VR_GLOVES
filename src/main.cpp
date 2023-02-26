#include <Arduino.h>
#include "tasks.h"
#include "leds.h"
#include "buttons.h"
#include "bleComms.h"

void setup()
{
  Serial.begin(9600);
  ledsInit();
  buttonInit();
  bluetoothInit(); 
  taskCreate();
}

void loop()
{
  // put your main code here, to run repeatedly:
}