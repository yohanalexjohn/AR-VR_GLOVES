#include "tasks.h"
#include "leds.h"
#include "buttons.h"
#include "bleComms.h"

// RTOS Private Function Declarations

static void vTaskHandler_Main(void *pvParameters);
static void vTaskHandler_Leds(void *pvParameters);
static void vTaskHandler_Button(void *pvParameters);
static void vTaskHandler_Bluetooth(void *pvParameters);
// @TODO: ADD INTERUPTS FOR BLUETOOTH RECIEVE

// RTOS Services
QueueHandle_t xQueue_Leds, xQueue_Button, xQueue_BluetoothSend; 

// PUBLIC FUNCTION DEFINITIONS

// Create tasks
void taskCreate(void)
{
    xQueue_Leds           = xQueueCreate(1, sizeof(int));  // LEDs Queue will eventually call this the motors queue
    xQueue_Button         = xQueueCreate(1, sizeof(int));  // Buttons Queue will remame this to touch queue once touch is enabled 
    xQueuen_BluetoothSend = xQueueCreate(1, sizeof(int));  // Bluetooth send Queue

    // Check if queues are initalised succesfully for data trasnfer between module
    if( xQueue_Leds != NULL && xQueue_Button != NULL && xQueue_BluetoothSend != NULL )
    {
        // Create the tasks and pin them to their respective cores
            // Header                TaskHandler             TaskName for debugging   Stack Size   InParameters  Priority  TaskReference  Core
            xTaskCreatePinnedToCore( vTaskHandler_Main,      "Task Main Brain",       1000,        NULL,         3,        NULL,           1 );
            xTaskCreatePinnedToCore( vTaskHandler_Bluetooth, "Task Main Bluetooth",   900,         NULL,         2,        NULL,           0 );
            xTaskCreatePinnedToCore( vTaskHandler_Button,    "Task Main Button",      800 ,        NULL,         1,        NULL,           1 );
            xTaskCreatePinnedToCore( vTaskHandler_Leds,      "Task Main LEDs",        800,         NULL,         1,        NULL,           0 );
    }
    else
    {
        /* code */
    }
    

}
