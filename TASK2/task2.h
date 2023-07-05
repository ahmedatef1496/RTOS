

#ifndef _TASK2_H
#define _TASK2_H

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


#define LED1_PORT		          PORT_0
#define LED1_PIN		          PIN1
#define LED1_TASK_PRIORITY        1
#define LED1_TASK_STACK_SIZE  	  100
#define LED1_TASK_NAME			  "Toggle LED1 Task"

#define LED2_PORT		          PORT_0
#define LED2_PIN		          PIN2
#define LED2_TASK_PRIORITY     `	  1
#define LED2_TASK_STACK_SIZE      100
#define LED2_TASK_NAME			  "Toggle LED2 Task"

#define LED3_PORT		          PORT_0
#define LED3_PIN		          PIN3
#define LED3_TASK_PRIORITY         1
#define LED3_TASK_STACK_SIZE      100
#define LED3_TASK_NAME			  "Toggle LED3 Task"



#define LED1_DELAY    100

#define LED2_DELAY    500

#define LED3_DELAY    1000

void Task2_create(void);

			
#endif //_TASK2_H
