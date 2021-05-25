/*
 * BlueTask.h
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */

#ifndef INC_BLUETASK_H_
#define INC_BLUETASK_H_


extern EventGroupHandle_t BlueEvent;

#define BLUE_EVT 		(1<<0)
#define BLUE_NOT_EVT	(1<<1)

void BlueFunc(void const * argument);


#endif /* INC_BLUETASK_H_ */
