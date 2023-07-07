
#include "A2_task3.h"

/* Tasks Handlers */
TaskHandle_t Button1Task_Handler = NULL;
TaskHandle_t Button2Task_Handler = NULL;
TaskHandle_t CTask_Handler = NULL;
TaskHandle_t PTask_Handler = NULL;


static void Button1_task( void * pvParameters );
static void Button2_task( void * pvParameters );
static void Consumer_task( void * pvParameters );
static void Periodic_task( void * pvParameters );

/* Global Variables */ 




/* create a Queue */
QueueHandle_t xUARTQueue;

void A2_Task3create(void)
{
	xUARTQueue = xQueueCreate( QueueLength, ItemSize  ); 
	
	xTaskCreate(Button1_task,  BTN1TASK_NAME, BTN1TASK_STACK_SIZE, NULL, BTN1TASK_PRIORITY, &Button1Task_Handler );
	xTaskCreate(Button2_task,  BTN2TASK_NAME, BTN2TASK_STACK_SIZE, NULL, BTN2TASK_PRIORITY, &Button2Task_Handler );
	xTaskCreate(Consumer_task, CTASK_NAME,    CTASK_STACK_SIZE,    NULL, CTASK_PRIORITY,    &CTask_Handler );
	xTaskCreate(Periodic_task, PTASK_NAME,    PTASK_STACK_SIZE,    NULL, PTASK_PRIORITY,    &PTask_Handler );
}

void Button1_task( void * pvParameters )
{
		pinState_t BTN1State1 = PIN_IS_LOW;
		pinState_t BTN1State2;
    for( ;; )
    {
				BTN1State2 = GPIO_read(BTN1_PORT, BTN1_PIN);
			  /* Case Rising Edge */
				if(BTN1State1 == PIN_IS_LOW && BTN1State2 == PIN_IS_HIGH)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"BTN1 RISING" , portMAX_DELAY );
				}
				/* Case Falling Edge */
				else if(BTN1State1 == PIN_IS_HIGH && BTN1State2 == PIN_IS_LOW)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"BTN1 FALLING" , portMAX_DELAY );
				}
				BTN1State1 = BTN1State2;
				vTaskDelay(100);
    }
}

void Button2_task( void * pvParameters )
{
	  pinState_t BTN2State1 = PIN_IS_LOW;
    pinState_t BTN2State2;
    for( ;; )
    {
				BTN2State2 = GPIO_read(BTN2_PORT, BTN2_PIN);
			  /* Case Rising Edge */
				if(BTN2State1 == PIN_IS_LOW && BTN2State2 == PIN_IS_HIGH)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"BTN2  RISING" , portMAX_DELAY );
				}
				/* Case Falling Edge */
				else if(BTN2State1 == PIN_IS_HIGH && BTN2State2 == PIN_IS_LOW)
				{
						xQueueSend( xUARTQueue, ( unsigned char * )"BTN2 FALLING" , portMAX_DELAY );
				}
				BTN2State1 = BTN2State2;
				vTaskDelay(100);
		}
}

void Consumer_task( void * pvParameters )
{
		uint8_t UART_str[12];
    for( ;; )
    {
				xQueueReceive(xUARTQueue, UART_str, portMAX_DELAY);
			  vSerialPutString((const signed char * const)UART_str, 12);
				vTaskDelay(100);
				xSerialPutChar('\n');
		}
}

void Periodic_task( void * pvParameters )
{
    for( ;; )
    {
				xQueueSend( xUARTQueue, ( unsigned char * )"PeriodicString" , portMAX_DELAY );
				vTaskDelay(100);
		}
}