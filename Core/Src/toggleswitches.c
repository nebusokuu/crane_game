/*
 * toggleswitches.c
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#include "limitswitches.h"

bool isHigh_Toggle1(void) {
	return HAL_GPIO_ReadPin(Toggle1_GPIO_Port, Toggle1_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isHigh_Toggle2(void) {
	return HAL_GPIO_ReadPin(Toggle2_GPIO_Port, Toggle2_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isHigh_Toggle3(void) {
	return HAL_GPIO_ReadPin(Toggle3_GPIO_Port, Toggle3_Pin) != GPIO_PIN_RESET ? true : false;
}
