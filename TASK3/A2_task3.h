

#ifndef _A2_TASK2_H
#define _A2_TASK2_H

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "semphr.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"

#define BTN1_PORT												PORT_0
#define BTN1_PIN 												PIN0
#define BTN1TASK_PRIORITY 							4
#define BTN1TASK_STACK_SIZE         		100
#define BTN1TASK_NAME				       			"D Rising Edge Task"

#define BTN2_PORT												PORT_0
#define BTN2_PIN 												PIN1
#define BTN2TASK_PRIORITY 							3
#define BTN2TASK_STACK_SIZE         		100
#define BTN2TASK_NAME				       			"D Falling Edge Task"

#define CTASK_PRIORITY 								  1
#define CTASK_STACK_SIZE         			  100
#define CTASK_NAME				       			  "Consumer Task"

#define PTASK_PRIORITY 								2
#define PTASK_STACK_SIZE         			100
#define PTASK_NAME				       			  "Periodic_task"


#define   QueueLength      10
#define    ItemSize        20 * sizeof( unsigned char )
void A2_Task3create(void);

			
#endif //_A2_TASK2_H
