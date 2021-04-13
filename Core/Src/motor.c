/*
 * motor.c
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */
#include "tim.h"
#include "motor.h"

#define MD_DEADTIME (1)
#define PWM_MAX (100) // 99かも

void Set_Motor_X(int pwm) {
    //前回とGPIOが変化したら以下の回数だけGPIOを両方Lに
    static int wait = 0;
    //前回のGPIOの政府を記録しておく。指定時間0が続けば0に
    static int prev_state = 0;
    //出力が0になっている連続時間
    static int off_time = 0;

    if (wait > 0) {
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
        wait--;
        if (wait == 0) {
            prev_state = 0;
        }
    }
    else if (pwm == 0) {
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
        if (off_time >= MD_DEADTIME) {
            prev_state = 0;
        }
        else {
            off_time++;
        }
    }
    else if (pwm > 0) {
        off_time = 0;
        if (prev_state >= 0) {
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
            if (PWM_MAX < pwm) {
                HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, PWM_MAX);
            }
            else if (pwm < 0) {
                HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_RESET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
            }
            else {
                HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, pwm);
            }
        }
        else {
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
            wait = MD_DEADTIME;
        }
        prev_state = 1;
    }
    else {
        off_time = 0;
        if (prev_state <= 0) {
            HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_RESET);
            if (PWM_MAX < -pwm) {
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, PWM_MAX);
            }
            else if (-pwm < 0) {
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
            }
            else {
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, -pwm);
            }
        }
        else {
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(x_MDE14_GPIO_Port, x_MDE14_Pin, GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
            wait = MD_DEADTIME;
        }
        prev_state = -1;
    }
}

void Set_Motor_Y(int pwm) {
    //前回とGPIOが変化したら以下の回数だけGPIOを両方Lに
    static int wait = 0;
    //前回のGPIOの政府を記録しておく。指定時間0が続けば0に
    static int prev_state = 0;
    //出力が0になっている連続時間
    static int off_time = 0;

    if (wait > 0) {
        HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
        wait--;
        if (wait == 0) {
            prev_state = 0;
        }
    }
    else if (pwm == 0) {
        HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
        if (off_time >= MD_DEADTIME) {
            prev_state = 0;
        }
        else {
            off_time++;
        }
    }
    else if (pwm > 0) {
        off_time = 0;
        if (prev_state >= 0) {
            HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_RESET);
            if (PWM_MAX < pwm) {
                HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, PWM_MAX);
            }
            else if (pwm < 0) {
                HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_RESET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
            }
            else {
                HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pwm);
            }
        }
        else {
            HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
            wait = MD_DEADTIME;
        }
        prev_state = 1;
    }
    else {
        off_time = 0;
        if (prev_state <= 0) {
            HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_RESET);
            if (PWM_MAX < -pwm) {
                HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, PWM_MAX);
            }
            else if (-pwm < 0) {
                HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_RESET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
            }
            else {
                HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, -pwm);
            }
        }
        else {
            HAL_GPIO_WritePin(y_MDE11_GPIO_Port, y_MDE11_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(y_MDE10_GPIO_Port, y_MDE10_Pin, GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
            wait = MD_DEADTIME;
        }
        prev_state = -1;
    }
}

void Set_Motor_Z(int pwm) {
    //前回とGPIOが変化したら以下の回数だけGPIOを両方Lに
    static int wait = 0;
    //前回のGPIOの政府を記録しておく。指定時間0が続けば0に
    static int prev_state = 0;
    //出力が0になっている連続時間
    static int off_time = 0;

    if (wait > 0) {
        HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
        wait--;
        if (wait == 0) {
            prev_state = 0;
        }
    }
    else if (pwm == 0) {
        HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_RESET);
        __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
        if (off_time >= MD_DEADTIME) {
            prev_state = 0;
        }
        else {
            off_time++;
        }
    }
    else if (pwm > 0) {
        off_time = 0;
        if (prev_state >= 0) {
            HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_RESET);
            if (PWM_MAX < pwm) {
                HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, PWM_MAX);

            }
            else if (pwm < 0) {
                HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_RESET);
                __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);

            }
            else {
                HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, pwm);
            }
        }
        else {
            HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
            wait = MD_DEADTIME;
        }
        prev_state = 1;
    }
    else {
        off_time = 0;
        if (prev_state <= 0) {
            HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_RESET);
            if (PWM_MAX < -pwm) {
                HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, PWM_MAX);
            }
            else if (-pwm < 0) {
                HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_RESET);
                __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
            }
            else {
                HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_SET);
                __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, -pwm);
            }
        }
        else {
            HAL_GPIO_WritePin(z_MDD15_GPIO_Port, z_MDD15_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(z_MD_GPIO_Port,    z_MD_Pin,    GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 0);
            wait = MD_DEADTIME;
        }
        prev_state = -1;
    }
}

void Set_Motor_Half_1(uint32_t pwm) {
	if (pwm == 0) {
		HAL_GPIO_WritePin(HarfBridge_MD1C8_GPIO_Port, HarfBridge_MD1C8_Pin, GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, 0);
	}
	else {
		pwm = pwm > PWM_MAX ? PWM_MAX : pwm;
		HAL_GPIO_WritePin(HarfBridge_MD1C8_GPIO_Port, HarfBridge_MD1C8_Pin, GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, pwm);
	}
}

void Set_Motor_Half_2(uint32_t pwm) {
	if (pwm == 0) {
		HAL_GPIO_WritePin(HarfBridge_MD2A8_GPIO_Port, HarfBridge_MD2A8_Pin, GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, 0);
	}
	else {
		pwm = pwm > PWM_MAX ? PWM_MAX : pwm;
		HAL_GPIO_WritePin(HarfBridge_MD2A8_GPIO_Port, HarfBridge_MD2A8_Pin, GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, pwm);
	}
}
