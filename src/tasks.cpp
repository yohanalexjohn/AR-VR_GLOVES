#include "tasks.h"
#include "pinConfig.h"
#include "halSensor.h"

// PRIVATE FUNCTION DECLARTATIONS

/**
 * @brief Get the relative finger position
 *
 * @param pvParameters
 */
static void getSensorData(void *pvParameters);


void getSensorData(void *pvParameters)
{
    (void)pvParameters;

    for (;;)
    {
        float data;
        int sensor = 1;

        data = get_halValue(sensor);

        delay(100);
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

    // xTaskCreate(
    //     sendData,
    //     " Send data to pi",
    //     1000,
    //     NULL,
    //     2,
    //     NULL);

    // xTaskCreate(
    //     activateAlarm,
    //     "Activate the alarm",
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