
#include "task1.h"


/*************************************** Task 1 *************************************/
 TaskHandle_t TASK1Handler =NULL;
static void ToggleLEDTask( void * pvParameters );



void TASK1_create(void)
{
		xTaskCreate(ToggleLEDTask, TASK1_NAME, TASK1_STACK_SIZE, NULL, TASK1_PRIORITY, &TASK1Handler );
}


void ToggleLEDTask( void * pvParameters )
{
    for( ;; )
    {
			GPIO_write(LED_PORT, LED_PIN, PIN_IS_HIGH);
				
			vTaskDelay(1000);
				
			GPIO_write(LED_PORT, LED_PIN, PIN_IS_LOW);
				
			vTaskDelay(1000);
    }
}
