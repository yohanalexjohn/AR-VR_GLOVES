#include "tasks.h"
#include "pinConfig.h"
#include "halSensor.h"
#include "hapticMotor.h"

// Send data from producer to consumer
QueueHandle_t msg_queue;

/**
 * @brief store the sensor data
 *
 */
struct messageData
{
    float sensorPosition; // eventually this will be an array each position for each each sensor
};

// PRIVATE FUNCTION DECLARTATIONS

/**
 * @brief Get the relative finger position
 *
 * @param pvParameters
 */
static void getSensorData(void *pvParameters);

/**
 * @brief Get the relative finger position
 *
 * @param pvParameters
 */
static void motorState(void *pvParameters);

void motorState(void *pvParameters)
{
    (void)pvParameters;

    int sensor;
    float data;

    messageData motorDependency;

    for (;;)
    {
        if (xQueueReceive(msg_queue, &motorDependency, portMAX_DELAY))
        {
            // Soon turn this to array's to validate this for each sensor 
            hapticMotorFeature(sensor, data);
        }

        delay(10);
    }
}

void getSensorData(void *pvParameters)
{
    (void)pvParameters;

    float data;
    int sensor = 1;
    messageData halValue;

    for (;;)
    {
        data = get_halValue(sensor);

        // Send sensor values to the structure
        xQueueSend(msg_queue, &halValue, portMAX_DELAY);

        delay(10);
    }
}

// PUBLIC FUNCTION DEFINITIONS

// Create tasks
void taskCreate(void)
{
    xTaskCreate(
        getSensorData,
        " Gather Data ",
        1000,
        NULL,
        1,
        NULL);

    xTaskCreate(
        motorState,
        " decide if to turn the haptic motor on or off ",
        1000,
        NULL,
        1,
        NULL);

    // xTaskCreate(
    //     bluetooth,
    //     "enabling bluetooth connectivity and checking",
    //     1000,
    //     NULL,
    //     2,
    //     &alarmTaskHandler);

    // // Create a one-shot timer
    // one_shot_timer = xTimerCreate(
    //     "One-shot timer", // Name of timer
    //     dim_delay,        // Period of timer (in ticks)
    //     pdFALSE,          // Auto-reload
    //     (void *)0,        // Timer ID
    //     timeDoorCheck);   // Callback function

    // // Setup the message queue
    // msg_queue = xQueueCreate(QUEUE_LENGTH,
    //                          sizeof(sensorData));

    // // Suspend activateAlarm until it is resumed by the software timer
    // vTaskSuspend(alarmTaskHandler);

    vTaskDelete(NULL);
}