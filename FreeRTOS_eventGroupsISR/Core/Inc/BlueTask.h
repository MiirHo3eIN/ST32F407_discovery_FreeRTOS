/*
 * BlueTask.h
 *
 *  Created on: May 25, 2021
 *      Author: amirh
 */

#ifndef INC_BLUETASK_H_
#define INC_BLUETASK_H_


#define LED_BLUE_ON (1<<0)
#define SHUT_BLUE_LED (1<<1)

extern EventGroupHandle_t BlueEvent;

void BlueFunc(void const * argument);

#endif /* INC_BLUETASK_H_ */
