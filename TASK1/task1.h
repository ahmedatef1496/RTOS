

#ifndef _TASK1_H
#define _TASK1_H

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


#define LED_PORT		        PORT_0
#define LED_PIN		          PIN1
#define TASK1_PRIORITY     1
#define TASK1_STACK_SIZE   100
#define TASK1_NAME		  "Toggle LED Task"


#define   LED_DELAY         1000

void TASK1_create(void);

			
#endif //_TASK1_H
