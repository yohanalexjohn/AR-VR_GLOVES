/**
 * @file buttons.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#define TEST_PHASE_1

#ifdef TEST_PHASE_1

#include <ezButton.h>
#include "buttons.h"
#include "pinConfig.h"

#define BUTTON_MAX 4

// Setup Ezbutton array
ezButton buttonArray[BUTTON_MAX] = {
    ezButton(BUTTON_FORWARD),
    ezButton(BUTTON_BACKWARD),
    ezButton(BUTTON_RIGHT),
    ezButton(BUTTON_LEFT)
};

// Public Function Definitions
void buttonInit(void)
{
    // initilise the button pin as an input:
    for (int i = 0; i < BUTTON_MAX; i++)
    {
        buttonArray[i].setDebounceTime(50); // Set debounce Time to 50 milliseconds
    }
}

void buttonPressed(int *buttonID)
{
    for (int i = 0; i < BUTTON_MAX; i++)
    {
        buttonArray[i].loop();  // MUST call the loop() function first
    }
    
    for (int j = 0; j < BUTTON_MAX; j++) 
    {
        if (buttonArray[j].isPressed()) 
        {
            *buttonID = j; // Assigning the value of the button that is pressed to the button ID
        }
    }
}

#endif