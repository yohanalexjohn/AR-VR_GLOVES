/**
 * @file hapticMotor.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-11-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "hapticMotor.h"
#include "pinConfig.h"

// Private Member declarations

// Private Function Declarations

// Private Function Definitions

// Public Function Definitions
void vibrationMotorInit(void)
{
    // TODO - make a for loop and initilise them all in one go.
    pinMode(1, OUTPUT);
}

void hapticMotorFeature(int sensorNumber, float data)
{
    if (data != 0)
    {
        // tweak for releavant sensor
        tone(sensorNumber, 1000, 1000);
    }
}
