
#if 1
#ifndef _TASK3_H
#define _TASK3_H

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


#define LED_TASK_PORT		       PORT_0
#define LED_TASK_PIN		       PIN1
#define LED_TASK_TASK_PRIORITY     1
#define LED_STACK_SIZE             100
#define LED_TASK_NAME				   "Toggle LED Task"

#define BUTTON_PORT		          PORT_0
#define BUTTON_PIN		          PIN0
#define BUTTON_TASK_PRIORITY      1
#define BUTTON_TASK_STACK_SIZE    100
#define BUTTON_TASK_NAME		  "Button Task"


#define   DEFAULT_DELAY   0

#define   STATE1_DELAY   400

#define   STATE2_DELAY   100
void Task3_create(void);

			
#endif //_TASK3_H
#endif