/*
 * limitswitches.c
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#include "limitswitches.h"

bool isPressed_y_BackLimit(void) {
	return HAL_GPIO_ReadPin(y_BackLimit_GPIO_Port, y_BackLimit_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_y_FrontLimit(void) {
	return HAL_GPIO_ReadPin(y_FrontLimit_GPIO_Port, y_FrontLimit_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_x_LeftLimit(void) {
	return HAL_GPIO_ReadPin(x_LeftLimit_GPIO_Port, x_LeftLimit_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_x_RightLimit(void) {
	return HAL_GPIO_ReadPin(x_RightLimit_GPIO_Port, x_RightLimit_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_z_UpLimit(void) {
	return HAL_GPIO_ReadPin(z_UpLimit_GPIO_Port, z_UpLimit_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_z_Limit_Error(void) {
	return HAL_GPIO_ReadPin(z_Limit_Error_GPIO_Port, z_Limit_Error_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_z_BottomLimit_Hard(void) {
	return HAL_GPIO_ReadPin(z_BottomLimit_Hard_GPIO_Port, z_BottomLimit_Hard_Pin) != GPIO_PIN_RESET ? true : false;
}

bool isPressed_z_BottomLimit_Soft(void) {
	return HAL_GPIO_ReadPin(z_BottomLimit_Soft_GPIO_Port, z_BottomLimit_Soft_Pin) != GPIO_PIN_RESET ? true : false;
}
