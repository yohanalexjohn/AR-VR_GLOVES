/**
 * @file halSensor.cpp
 * @author AR-VR_GLOVES
 * @brief
 * @version 0.1
 * @date 2022-11-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "halSensor.h"
#include "pinConfig.h"

// Public Functions Definitions 

void halSensorInit(void)
{
    pinMode(HAL_SENSOR, INPUT);
    delay(100);
}

float get_halValue(int halSensorNumber)
{
    float halSensorValue;

    halSensorValue = digitalRead(halSensorNumber);
    return halSensorValue;
}