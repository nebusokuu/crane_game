/*
 * motor.h
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"

void Set_Motor_X(int pwm);
void Set_Motor_Y(int pwm);
void Set_Motor_Z(int pwm);
void Set_Motor_Half_1(uint32_t pwm);
void Set_Motor_Half_2(uint32_t pwm);

#endif /* INC_MOTOR_H_ */
