/*
 * OrangeTask.c
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
EventGroupHandle_t OrangeEvent;


/* USER CODE BEGIN Header_OrangeFunc */
/**
* @brief Function implementing the OrangeTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_OrangeFunc */
void OrangeFunc(void const * argument)
{
  /* USER CODE BEGIN OrangeFunc */
	OrangeEvent = xEventGroupCreate();
	EventBits_t uxBits;
#define IS_EVT(x) 	uxBits & x

	 osDelay(1);
	char *str1 = "EVENT_GROUP_ORANGE_CREATED_FAIL\r\n";
	char *str2 = "EVENT_GROUP_ORANGE_CREATED_SUCCESSFULLY\r\n";
	char *str3 = "==============================================\r\n";
	if (OrangeEvent == NULL) 	HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 300);
	else 	HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 300);
	HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen(str3), 300);
  /* Infinite loop */
  for(;;)
  {
	  uxBits =  xEventGroupWaitBits(
			  	  	  	  	  	  	  OrangeEvent,   /* The event group being tested. */
									  ORANGE_EVT | ORANGE_NOT_EVT, /* The bits within the event group to wait for. */
									  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
									  pdFALSE,       /* Don't wait for both bits, either bit will do. */
									  100 );		/* Wait a maximum of 100ms for either bit to be set. */


	  if (IS_EVT(ORANGE_EVT))
	  {
		  char *str1 = "ORANGE_LED_SWITCH_ON\r\n";
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, SET);
		  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  osDelay(1);
	  }

	  if (IS_EVT(ORANGE_NOT_EVT))
	  {
		  char *str1 = "ORANGE_LED_SWITCH_OFF\r\n";
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, RESET);
		  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  osDelay(1);
	  }

	  if ((IS_EVT(ORANGE_NOT_EVT) &  IS_EVT(ORANGE_EVT)) == 0 )
	  {
		  char *str1 = "NO_UPDATE_ORANGE\r\n";
		  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  osDelay(1);
	  }
    osDelay(1);
  }
  /* USER CODE END OrangeFunc */
}
