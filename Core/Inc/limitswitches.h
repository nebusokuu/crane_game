/*
 * limitswitches.h
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#ifndef INC_LIMITSWITCHES_H_
#define INC_LIMITSWITCHES_H_

#include "main.h"
#include "stdbool.h"

bool isPressed_y_BackLimit(void);
bool isPressed_y_FrontLimit(void);
bool isPressed_x_LeftLimit(void);
bool isPressed_x_RightLimit(void);
bool isPressed_z_UpLimit(void);
bool isPressed_z_Limit_Error(void);
bool isPressed_z_BottomLimit_Hard(void);
bool isPressed_z_BottomLimit_Soft(void);


#endif /* INC_LIMITSWITCHES_H_ */
