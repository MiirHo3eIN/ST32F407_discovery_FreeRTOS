/*
 * BlueTask.c
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */

/* System Headers */
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "event_groups.h"
#include "string.h"
#include "stdio.h"

/* Peripheral Headers */
#include "tim.h"
#include "usart.h"

/* Private Headers */
#include "BlueTask.h"
#include "OrangeTask.h"
#include "GreenTask.h"

#pragma GCC diagnostic ignored "-Wunused-variable"

/* Event Variables */
static StaticEventGroup_t BlueEventGroupBuffer;
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
	configASSERT( BlueEvent );


  /* Infinite loop */
  for(;;)
  {
	  uxBits = xEventGroupWaitBits(
			  	  	  	  	  BlueEvent,
							  LED_BLUE_ON	| SHUT_BLUE_LED,
							  pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
							  pdFALSE,       /* Don't wait for both bits, either bit will do. */
							  100  );


	  if (IS_EVT(LED_BLUE_ON))
	  {
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, SET);
		  char *str1 = "Blue Led Went On\r\n";
		  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  osDelay(50);
	  }
	  else
		  {
		  HAL_TIM_Base_Start_IT(&htim6);
		  char *str2 = "Timer 6 start to count\r\n\n";
		  HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 100);
		  }
	  if (IS_EVT(SHUT_BLUE_LED))
		  {
		  	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, RESET);
			  char *str1 = "Blue Led Went OFF\r\n";
			  HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 100);
		  }
    osDelay(1);
  }
  /* USER CODE END BlueFunc */
}
