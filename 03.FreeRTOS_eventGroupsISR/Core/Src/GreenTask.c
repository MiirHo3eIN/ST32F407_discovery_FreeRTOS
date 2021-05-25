/*
 * GreenTask.c
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
static StaticEventGroup_t GreenEventGroupBuffer;
EventGroupHandle_t GreenEvent;

/* USER CODE BEGIN Header_GreenFunc */
/**
* @brief Function implementing the GreenTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_GreenFunc */
void GreenFunc(void const * argument)
{
  /* USER CODE BEGIN GreenFunc */
	/* Internal Variables */
	GreenEvent = xEventGroupCreate();
	EventBits_t uxBits;
    #define IS_EVT(x) 	uxBits & x
	 osDelay(1);
	char *str1 = "EVENT_GROUP_GREEN_CREATED_FAIL\r\n";
	char *str2 = "EVENT_GROUP_GREEN_CREATED_SUCCESSFULLY\r\n";
	char *str3 = "==============================================\r\n";
	if (GreenEvent == NULL) 	HAL_UART_Transmit(&huart2, (uint8_t *)str1, strlen(str1), 300);
	else 	HAL_UART_Transmit(&huart2, (uint8_t *)str2, strlen(str2), 300);
	HAL_UART_Transmit(&huart2, (uint8_t *)str3, strlen(str3), 300);
	configASSERT( GreenEvent );
  /* Infinite loop */
  for(;;)
  {

    osDelay(1);
  }
  /* USER CODE END GreenFunc */
}
