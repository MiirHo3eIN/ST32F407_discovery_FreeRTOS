/*
 * GreenTask.h
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */

#ifndef INC_GREENTASK_H_
#define INC_GREENTASK_H_

#define GREEN_EVT 		(1<<0)
#define GREEN_NOT_EVT	(1<<1)



extern EventGroupHandle_t GreenEvent;



void GreenFunc(void const * argument);

#endif /* INC_GREENTASK_H_ */
