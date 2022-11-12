/**
 * @file halSensor.h
 * @author AR-VR_GLOVES 
 * @brief 
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// Public Functions Declarations for the Hal Linear sensor 

/**
 * @brief Intialise the hal sensors 
 * 
 */
void halSensorInit(void);

/**
 * @brief Get the halValue object
 * 
 * @param [in] halSensorNumber is id of the HAL sensor to get the value from
 * @return float The normalised finger position
 */
float get_halValue(int halSensorNumber);