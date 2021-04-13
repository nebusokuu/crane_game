/*
 * buttons.h
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#include "main.h"
#include "stdbool.h"

bool isPressed_x_PushButton(void);
bool isPressed_y_PushButton(void);
bool isPressed_LED7seg_CountUP(void);
bool isPressed_LED7seg_CountDown(void);

bool isPressed_CoinSelecter_100(void);

#endif /* INC_BUTTONS_H_ */
