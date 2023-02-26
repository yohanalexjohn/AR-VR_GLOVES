/**
 * @file leds.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "leds.h"

// Phase 1 of development will use leds to simulate behaviour of Haptic Motors
// Phase 2 of development will use leds & motors to show haptic feedback for visual and sensory effects
// Phase 3 of development will use leds to show Bluetooth connection receiving and sending

#define TEST_PHASE_1

// Max led count
#define LED_MAX 4

// Brightness settings
#define BRIGHT_MAX 255
#define BRIGHT_MIN 0

// Public Functions Definition

void ledsInit(void)
{
    // Initilise the led pins as an output
    pinMode(LED_FORWARD, OUTPUT);
    pinMode(LED_BACKWARD, OUTPUT);
    pinMode(LED_RIGHT, OUTPUT);
    pinMode(LED_LEFT, OUTPUT);

    Serial.println("LEDs Initlaised");
}

void performFade(int ledPin)
{
    int fadeAmount = 5;
    int brightValue = 0;

    brightValue += fadeAmount;

    // reverse the direction of the fading when it reaches 0 or 255
    if (brightValue <= BRIGHT_MIN || brightValue >= BRIGHT_MAX)
    {
        fadeAmount = -fadeAmount;
    }

    Serial.println(brightValue);
    analogWrite(ledPin, brightValue);
}

void setLedHigh(int ledPin)
{
    analogWrite(ledPin, BRIGHT_MAX);
}

void setLedLow(int ledPin)
{
    analogWrite(ledPin, BRIGHT_MIN);
}

void setLedValue(int ledPin, int value)
{
    analogWrite(ledPin, value);
}
