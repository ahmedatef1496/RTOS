
#include "A2_task2.h"


TaskHandle_t Task2_UART1Handler = NULL;
TaskHandle_t Task2_UART2Handler = NULL;

static void Task2_UART1( void * pvParameters );
static void Task2_UART2( void * pvParameters );

/* create a semaphore */
SemaphoreHandle_t xMutex;
SemaphoreHandle_t xSemaphore1 = NULL;

void A2_Task2create(void)
{
	xMutex = xSemaphoreCreateMutex();
	xTaskCreate(Task2_UART1, TASK1_NAME,  TASK1_STACK_SIZE, NULL, TASK1_PRIORITY, &Task2_UART1Handler );
	xTaskCreate(Task2_UART2, TASK2_NAME,  TASK2_STACK_SIZE, NULL, TASK2_PRIORITY, &Task2_UART2Handler );
}

void Task2_UART1( void * pvParameters )
{
	uint8_t u8count = 0;
	uint32_t u32count2 = 0;
    for( ;; )
    {
			xSemaphoreTake( xMutex, portMAX_DELAY );
			
				for(u8count=0; u8count<10; u8count++)
				{
						vSerialPutString((const signed char * const)"task100", 8);
						/* Wait until string is transmitted. */
						while(txDataSizeLeftToSend != 0);
				}
				xSerialPutChar('\n');
				xSemaphoreGive( xMutex );
			
			vTaskDelay(100);
    }
}


void Task2_UART2( void * pvParameters )
{
		uint8_t u8count1 = 0;
		uint32_t u32count2 = 0;
    for( ;; )
    {
			xSemaphoreTake( xMutex, portMAX_DELAY );
			
				for(u8count1=0; u8count1<10; u8count1++)
				{
						vSerialPutString((const signed char * const)"task500", 8);
						for(u32count2=0; u32count2<100000; u32count2++);
				}
				xSerialPutChar('\n');
				xSemaphoreGive( xMutex );
			
			vTaskDelay(500);
		}
}
