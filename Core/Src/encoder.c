/*
 * encoder.c
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#include "encoder.h"

int16_t Get_x_Enc(void) {
	return (int16_t) TIM5->CNT;
}

int16_t Get_y_Enc(void) {
	return (int16_t) TIM3->CNT;
}

int16_t Get_z_Enc(void) {
	return (int16_t) TIM4->CNT;
}

void Set_x_Enc(int32_t val) {
    TIM5->CNT = val;
}

void Set_y_Enc(int32_t val) {
    TIM3->CNT = val;
}

void Set_z_Enc(int32_t val) {
    TIM4->CNT = val;
}
