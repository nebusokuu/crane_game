/*
 * buttons.c
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#include "buttons.h"

bool isPressed_x_PushButton(void) {
	return HAL_GPIO_ReadPin(x_PushButton_GPIO_Port, x_PushButton_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_y_PushButton(void) {
	return HAL_GPIO_ReadPin(y_PushButton_GPIO_Port, y_PushButton_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_LED7seg_CountUP(void) {
    return HAL_GPIO_ReadPin(LED7seg_CountUp_GPIO_Port, LED7seg_CountUp_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_LED7seg_CountDown(void) {
    return HAL_GPIO_ReadPin(LED7seg_CountDown_GPIO_Port, LED7seg_CountDown_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_CoinSelecter_100(void) {
    return HAL_GPIO_ReadPin(CoinSellecter_100_GPIO_Port, CoinSellecter_100_Pin) != GPIO_PIN_RESET ? true : false;
}
