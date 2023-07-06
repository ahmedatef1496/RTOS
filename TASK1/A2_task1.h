

#ifndef _A2_TASK1_H
#define _A2_TASK1_H

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


#define TASK1_LED_PORT		       					PORT_0
#define TASK1_LED_PIN		       						PIN1
#define TASK1_LED_TASK_PRIORITY 					1
#define TASK1_LED_TASK_STACK_SIZE         100
#define TASK1_LED_TASK_NAME				       "Toggle LED Task"

#define TASK1_BTN_PORT		          					PORT_0
#define TASK1_BTN_PIN		          						PIN0
#define TASK1_BTN_TASK_PRIORITY    						1
#define TASK1_BTN_TASK_STACK_SIZE  						100
#define TASK1_BTN_TASK_NAME										"Button Task"



void A2_Task1create(void);

			
#endif //_A2_TASK1_H
