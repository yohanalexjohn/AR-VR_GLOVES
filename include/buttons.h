/**
 * @file buttons.h
 * @author your name (you@domain.com)
 * @brief A wrapper file for the ezButton library 
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#define TEST_PHASE_1

#ifdef TEST_PHASE_1
/**
 * @brief Initialise all the buttons in to be used 
 * 
 */
void buttonInit(void);

/**
 * @brief Returns the type of button that is pressed 
 * 
 * @param buttonID takes in the poiter that will assign the button that is pressed 
 */
void buttonPressed(int *buttonID);
#endif