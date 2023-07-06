
#include "A2_task1.h"


TaskHandle_t TASK1_ButtonTaskHandler = NULL;
TaskHandle_t TASK1_ToggleTaskHandler = NULL;

static void Task1_ToggleTask( void * pvParameters );
static void Task1_ButtonTask( void * pvParameters );

/* create a semaphore */
SemaphoreHandle_t InputSemaphore = NULL;

void A2_Task1create(void)
{
	InputSemaphore = xSemaphoreCreateBinary();
	xTaskCreate(Task1_ToggleTask, TASK1_LED_TASK_NAME, TASK1_LED_TASK_STACK_SIZE, NULL, TASK1_LED_TASK_PRIORITY, &TASK1_ToggleTaskHandler );
	xTaskCreate(Task1_ButtonTask, TASK1_BTN_TASK_NAME, TASK1_BTN_TASK_STACK_SIZE, NULL, TASK1_BTN_TASK_PRIORITY, &TASK1_ButtonTaskHandler );
}

void Task1_ToggleTask( void * pvParameters )
{
		pinState_t LEDState = PIN_IS_LOW;
	
    for( ;; )
    {
				if( xSemaphoreTake( InputSemaphore, ( TickType_t ) 10 ) == pdTRUE )
				{
						if(LEDState == PIN_IS_LOW)
						{
								LEDState = PIN_IS_HIGH;
						}
						else if(LEDState == PIN_IS_HIGH)
						{
								LEDState = PIN_IS_LOW;
						}
						GPIO_write(TASK1_LED_PORT, TASK1_LED_PIN, LEDState);
				}
				vTaskDelay(50);
    }
}


void Task1_ButtonTask( void * pvParameters )
{
	pinState_t ButtonState;
	uint8_t u8Flag=0;
	
    for( ;; )
    {
			ButtonState = GPIO_read(TASK1_BTN_PORT, TASK1_BTN_PIN);
			if(ButtonState==PIN_IS_HIGH && u8Flag==0)
			{
				u8Flag = 1;
			}
			else if(ButtonState==PIN_IS_LOW && u8Flag==1)
			{
				u8Flag = 0;
				xSemaphoreGive( InputSemaphore );
			}
			vTaskDelay(50);
		}

}
