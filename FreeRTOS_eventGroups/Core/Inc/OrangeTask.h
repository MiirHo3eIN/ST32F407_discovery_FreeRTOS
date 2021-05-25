/*
 * OrangeTask.h
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */

#ifndef INC_ORANGETASK_H_
#define INC_ORANGETASK_H_

extern EventGroupHandle_t OrangeEvent;

#define ORANGE_EVT 		(1<<0)
#define ORANGE_NOT_EVT	(1<<1)


void OrangeFunc(void const * argument);
#endif /* INC_ORANGETASK_H_ */
