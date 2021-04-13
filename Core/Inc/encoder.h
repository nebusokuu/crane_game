/*
 * encoder.h
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include "main.h"

int16_t Get_x_Enc(void);
int16_t Get_y_Enc(void);
int16_t Get_z_Enc(void);
void Set_x_Enc(int32_t val);
void Set_y_Enc(int32_t val);
void Set_z_Enc(int32_t val);

#endif /* INC_ENCODER_H_ */
