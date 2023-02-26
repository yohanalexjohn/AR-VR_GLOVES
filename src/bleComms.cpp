/**
 * @file bleComms.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <BleKeyboard.h>
#include "bleComms.h"

// BLE OBJECT SETUP
BleKeyboard bleKeyboard("Ring Controller");


typedef enum {
    DIRECTION_FORWARD,
    DIRECTION_BACKWARD,
    DIRECTION_RIGHT,
    DIRECTION_LEFT,
}direction;

typedef enum{
    KEY_FORWARD = KEY_UP_ARROW,
    KEY_BACKWARD = KEY_DOWN_ARROW,
    KEY_RIGHT = KEY_RIGHT_ARROW,
    KEY_LEFT = KEY_LEFT_ARROW,
}keyPress;
// Private Function Definitions


//Public Function Definitions
void bluetoothInit(void)
{
    bleKeyboard.begin();
}

void bluetoothSend(int direction)
{
    switch (direction) 
    {

        case DIRECTION_FORWARD:
            bleKeyboard.write(KEY_FORWARD);
            break;

        case DIRECTION_BACKWARD:
            bleKeyboard.write(KEY_BACKWARD);
            break;

        case DIRECTION_RIGHT:
            bleKeyboard.write(KEY_RIGHT);
            break;

        case DIRECTION_LEFT:
            bleKeyboard.write(KEY_LEFT_ARROW);
    } 
}

void bluetoothRecieve(int motorFeedback)
{
    // @TODO: send the motor to turn on back to the motor queue 

}