/*
 * dipswitches.c
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#include "dipswitches.h"

bool isHigh_DIP_SW1(void) {
	return HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isHigh_DIP_SW2(void) {
	return HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isHigh_DIP_SW3(void) {
	return HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin) != GPIO_PIN_RESET ? true : false;
}
