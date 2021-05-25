/*
 * BlueTask.c
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
EventGroupHandle_t BlueEvent;



/* USER CODE BEGIN Header_BlueFunc */
/**
  * @brief  Function implementing the BlueTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_BlueFunc */
void BlueFunc(void const * argument)
{
  /* USER CODE BEGIN BlueFunc */
	/* Internal Variables */
	BlueEvent = xEventGroupCreate();
	EventBits_t uxBits;
#define IS_EVT(x) 	uxBits & x
	 osDelay(1);
	char *str1 = "EVENT_GROUP_BLUE_CREATED_FAIL\r\n";
	char *str2 = "EVENT_GROUP_BLUE_CREATED_SUCCESSFULLY\r\n";
	char *str3 = "==============================================\r\n";
	if (BlueEvent == NULL) 	HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 300);
	else 	HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 300);
	HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen(str3), 300);

  /* Infinite loop */
  for(;;)
  {
	  uxBits =  xEventGroupWaitBits(
			  	  	  	  	  	  	  BlueEvent,   /* The event group being tested. */
									  BLUE_EVT | BLUE_NOT_EVT, /* The bits within the event group to wait for. */
									  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
									  pdFALSE,       /* Don't wait for both bits, either bit will do. */
									  100 );		/* Wait a maximum of 100ms for either bit to be set. */

	  if (IS_EVT(BLUE_EVT))
	  {
		  char *str1 = "BLUE_LED_SWITCH_ON\r\n";
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, SET);
		  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  osDelay(1);
	  }

	  if (IS_EVT(BLUE_NOT_EVT))
	  {
		  char *str1 = "BLUE_LED_SWITCH_OFF\r\n";
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, RESET);
		  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  osDelay(1);
	  }

	  if ((IS_EVT(BLUE_NOT_EVT) &  IS_EVT(BLUE_EVT)) == 0)
	  {
		  char *str1 = "NO_UPDATE_BLUE\r\n";
		  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  osDelay(1);
	  }

  }
  /* USER CODE END BlueFunc */
}
