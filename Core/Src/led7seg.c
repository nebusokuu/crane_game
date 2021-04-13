/*
 * led7seg.c
 *
 *  Created on: 2019/09/14
 *      Author: masahiro
 */

#include "led7seg.h"

// 出力は全て反転 DがMSB
void Display_led7seg(uint8_t num) {
    switch (num) {
        case 0://ok
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_SET);
            break;
        case 5:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_RESET);
            break;
        case 6://ok
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_SET);
            break;
        case 7:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_RESET);
            break;
        case 8:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_SET);
            break;
        case 9://ok
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_RESET);
            break;
        case 10://ok
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_SET);
            break;
        case 13:
            HAL_GPIO_WritePin(LED7seg_A_GPIO_Port, LED7seg_A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_B_GPIO_Port, LED7seg_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED7seg_C_GPIO_Port, LED7seg_C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED7seg_D_GPIO_Port, LED7seg_D_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}
