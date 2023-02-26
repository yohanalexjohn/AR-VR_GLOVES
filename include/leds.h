/**
 * @file leds.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "pinConfig.h"

/**
 * @brief Initialise the leds with their pin config and set them to output
 *
 */
void ledsInit();

/**
 * @brief Perform Fade to the leds
 *
 * @param led led pin number
 */
void perfromFade(int led);

/**
 * @brief Set the Led Pin to High
 *
 * @param led led pin number
 */
void setLedHigh(int led);

/**
 * @brief Set the Led Pin to Low
 *
 * @param led led pin number
 */
void setLedLow(int led);

/**
 * @brief Set the Led to a Custom Value 
 *        Should be called to set the led to a custome value of brightness 
 * 
 * @param led led pin number
 * @param value led voltage value which affects brightness 
 */
void setLedValue(int led, int value);