#if 1
#include "task3.h"


TaskHandle_t ButtonHandler = NULL;
TaskHandle_t ToggleHandler = NULL;

void ToggleTask( void * pvParameters );
void ButtonTask( void * pvParameters );

uint16_t gu16ToggleTime;

void Task3_create(void)
{
	xTaskCreate(ButtonTask, BUTTON_TASK_NAME, BUTTON_TASK_STACK_SIZE, NULL, BUTTON_TASK_PRIORITY, &ButtonHandler );
	xTaskCreate(ToggleTask, LED_TASK_NAME, LED_STACK_SIZE, NULL, LED_TASK_TASK_PRIORITY, &ToggleHandler );
}

void ToggleTask( void * pvParameters )
{
    for( ;; )
    {
			if(gu16ToggleTime == 0)
			{
				GPIO_write(LED_TASK_PORT, LED_TASK_PIN, PIN_IS_LOW);
				vTaskDelay(50);
			}
			else
			{
				GPIO_write(LED_TASK_PORT, LED_TASK_PIN, PIN_IS_HIGH);
				
				vTaskDelay(gu16ToggleTime);
				
				GPIO_write(LED_TASK_PORT, LED_TASK_PIN, PIN_IS_LOW);
				
				vTaskDelay(gu16ToggleTime);
			}
    }
}


void ButtonTask( void * pvParameters )
{
	pinState_t ButtonState;
	TickType_t startTicks = 0;
	TickType_t endTicks = 0;
	uint16_t u16PressTime = 0;
	static uint8_t u8Flag = 0;
	
    for( ;; )
    {
        /* Task code goes here. */
			ButtonState = GPIO_read(BUTTON_PORT, BUTTON_PIN);
			if(ButtonState==PIN_IS_HIGH && u8Flag==0)
			{
				startTicks = xTaskGetTickCount();
				u8Flag = 1;
			}
			if(ButtonState==PIN_IS_LOW && u8Flag==1)
			{
				u8Flag = 0;
				endTicks = xTaskGetTickCount();
				u16PressTime = (endTicks - startTicks) / configTICK_RATE_HZ;
				
				if(u16PressTime > SHORTPRESS && u16PressTime < LONGPRESS)
				{
					gu16ToggleTime = STATE1_DELAY;
				}
				else if(u16PressTime > LONGPRESS)
				{
					gu16ToggleTime = STATE2_DELAY;
				}
				else if(u16PressTime < SHORTPRESS)
				{
					gu16ToggleTime = DEFAULT_DELAY;
				}
			}
			vTaskDelay(50);
    }
}
#endif