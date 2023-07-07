

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


#define TASK1_PRIORITY 								2
#define TASK1_STACK_SIZE         			100
#define TASK1_NAME				       			"UART Task1"

#define TASK2_PRIORITY    						1
#define TASK2_STACK_SIZE  						100
#define TASK2_NAME										"UART Task5"



void A2_Task2create(void);

			
#endif //_A2_TASK2_H
