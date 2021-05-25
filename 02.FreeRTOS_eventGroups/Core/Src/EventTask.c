/*
 * EventTask.c
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */


/* Main Includes */
#include "main.h"
#include "stdio.h"
#include "string.h"
/* FreeRTOS includes */

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "event_groups.h"
/* Periph includes */
#include "usart.h"
/* task includes */
#include "BlueTask.h"
#include "GreenTask.h"
#include "OrangeTask.h"
#include "EventTask.h"

/* event variables */
  int i = 0,j = 0;



/* USER CODE BEGIN Header_EventFunc */
/**
* @brief Function implementing the EventTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_EventFunc */
void EventFunc(void const * argument)
{
  /* USER CODE BEGIN EventFunc */

	/* Infinite loop */
  for(;;)
  {

	    if (i == 1) 			 Set_Event(BlueEvent, BLUE_EVT);
		if (i == 1000)			 Set_Event(OrangeEvent, ORANGE_EVT);
		if (i == 1500)
			{
			Set_Event(BlueEvent, BLUE_NOT_EVT);
			Set_Event(GreenEvent, GREEN_EVT);
			}

		if (j==3000)
		{
			Set_Event(GreenEvent, GREEN_NOT_EVT);
			Set_Event(OrangeEvent, ORANGE_NOT_EVT);
			j = 0;
			i = 0;
		}
		i++;
		j++;
		osDelay(5);
  }
  /* USER CODE END EventFunc */
}
