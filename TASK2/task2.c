
#include "task2.h"


/*************************************** Task 2 *************************************/
TaskHandle_t ToggleLED1Handler = NULL;
TaskHandle_t ToggleLED2Handler = NULL;
TaskHandle_t ToggleLED3Handler = NULL;

static  void ToggleLED1Task( void * pvParameters );
static  void ToggleLED2Task( void * pvParameters );
static  void ToggleLED3Task( void * pvParameters );

void Task2_create(void)
{
	xTaskCreate(ToggleLED1Task, LED1_TASK_NAME, LED1_TASK_STACK_SIZE, NULL, 1, &ToggleLED1Handler );
	xTaskCreate(ToggleLED2Task, LED2_TASK_NAME, LED2_TASK_STACK_SIZE, NULL, 1, &ToggleLED2Handler );
	xTaskCreate(ToggleLED3Task, LED3_TASK_NAME, LED3_TASK_STACK_SIZE, NULL, 1, &ToggleLED3Handler );
}

/* Task to be created. */
void ToggleLED1Task( void * pvParameters )
{
    for( ;; )
    {
        /* Task code goes here. */
			GPIO_write(LED1_PORT, LED1_PIN, PIN_IS_HIGH);
			
			vTaskDelay(LED1_DELAY);
			
			GPIO_write(LED1_PORT, LED1_PIN, PIN_IS_LOW);
			
			vTaskDelay(LED1_DELAY);
    }
}

/* Task to be created. */
void ToggleLED2Task( void * pvParameters )
{
    for( ;; )
    {
        /* Task code goes here. */
			GPIO_write(LED2_PORT, LED2_PIN, PIN_IS_HIGH);
			
			vTaskDelay(LED2_DELAY);
			
			GPIO_write(LED2_PORT, LED2_PIN, PIN_IS_LOW);
			
			vTaskDelay(LED2_DELAY);
    }
}

/* Task to be created. */
void ToggleLED3Task( void * pvParameters )
{
    for( ;; )
    {
        /* Task code goes here. */
			GPIO_write(LED3_PORT, LED3_PIN, PIN_IS_HIGH);
			
			vTaskDelay(LED3_DELAY);
			
			GPIO_write(LED3_PORT, LED3_PIN, PIN_IS_LOW);
			
			vTaskDelay(LED3_DELAY);
    }
}