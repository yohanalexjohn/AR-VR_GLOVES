/**
 * @file hapticMotor.h
 * @author AR-VR_GLOVES 
 * @brief 
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Public Function Declartions

/**
 * @brief Initialise all the haptic feedback motors
 * 
 */
void vibrationMotorInit(void);

/**
 * @brief Perform the logic to all the Haptic features
 * 
 * @param [in] sensorNumber the sensor from which we get acitvate the relevant motor 
 * @param [in] data the value of each of this sensor 
 */
void hapticMotorFeature(int sensorNumber, float data);