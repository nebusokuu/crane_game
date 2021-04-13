/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define y_FrontLimit_Pin GPIO_PIN_2
#define y_FrontLimit_GPIO_Port GPIOE
#define x_RightLimit_Pin GPIO_PIN_3
#define x_RightLimit_GPIO_Port GPIOE
#define x_LeftLimit_Pin GPIO_PIN_4
#define x_LeftLimit_GPIO_Port GPIOE
#define Toggle1_Pin GPIO_PIN_13
#define Toggle1_GPIO_Port GPIOC
#define Toggle2_Pin GPIO_PIN_14
#define Toggle2_GPIO_Port GPIOC
#define Toggle3_Pin GPIO_PIN_15
#define Toggle3_GPIO_Port GPIOC
#define x_LimitControl_VR_Pin GPIO_PIN_0
#define x_LimitControl_VR_GPIO_Port GPIOC
#define y_LimitControl_VR_Pin GPIO_PIN_1
#define y_LimitControl_VR_GPIO_Port GPIOC
#define z_LimitControl_VR_Pin GPIO_PIN_2
#define z_LimitControl_VR_GPIO_Port GPIOC
#define arg_LimitControl_VR_Pin GPIO_PIN_3
#define arg_LimitControl_VR_GPIO_Port GPIOC
#define x_Enc_A_Pin GPIO_PIN_0
#define x_Enc_A_GPIO_Port GPIOA
#define x_Enc_B_Pin GPIO_PIN_1
#define x_Enc_B_GPIO_Port GPIOA
#define RangeFinder_Pin GPIO_PIN_4
#define RangeFinder_GPIO_Port GPIOA
#define y_Enc_A_Pin GPIO_PIN_6
#define y_Enc_A_GPIO_Port GPIOA
#define y_Enc_B_Pin GPIO_PIN_7
#define y_Enc_B_GPIO_Port GPIOA
#define DIP_SW1_Pin GPIO_PIN_4
#define DIP_SW1_GPIO_Port GPIOC
#define DIP_SW2_Pin GPIO_PIN_5
#define DIP_SW2_GPIO_Port GPIOC
#define DIP_SW3_Pin GPIO_PIN_0
#define DIP_SW3_GPIO_Port GPIOB
#define LED7seg_CountDown_Pin GPIO_PIN_1
#define LED7seg_CountDown_GPIO_Port GPIOB
#define LED7seg_CountUp_Pin GPIO_PIN_2
#define LED7seg_CountUp_GPIO_Port GPIOB
#define y_PushButton_Pin GPIO_PIN_7
#define y_PushButton_GPIO_Port GPIOE
#define x_PushButton_Pin GPIO_PIN_8
#define x_PushButton_GPIO_Port GPIOE
#define y_MD_Pin GPIO_PIN_9
#define y_MD_GPIO_Port GPIOE
#define y_MDE10_Pin GPIO_PIN_10
#define y_MDE10_GPIO_Port GPIOE
#define y_MDE11_Pin GPIO_PIN_11
#define y_MDE11_GPIO_Port GPIOE
#define x_MD_Pin GPIO_PIN_13
#define x_MD_GPIO_Port GPIOE
#define x_MDE14_Pin GPIO_PIN_14
#define x_MDE14_GPIO_Port GPIOE
#define CoinSellecter_100_Pin GPIO_PIN_10
#define CoinSellecter_100_GPIO_Port GPIOD
#define CoinSellecter_500_Pin GPIO_PIN_11
#define CoinSellecter_500_GPIO_Port GPIOD
#define z_Enc_A_Pin GPIO_PIN_12
#define z_Enc_A_GPIO_Port GPIOD
#define z_Enc_B_Pin GPIO_PIN_13
#define z_Enc_B_GPIO_Port GPIOD
#define z_MD_Pin GPIO_PIN_14
#define z_MD_GPIO_Port GPIOD
#define z_MDD15_Pin GPIO_PIN_15
#define z_MDD15_GPIO_Port GPIOD
#define z_MDC6_Pin GPIO_PIN_6
#define z_MDC6_GPIO_Port GPIOC
#define HarfBridge_MD1_Pin GPIO_PIN_7
#define HarfBridge_MD1_GPIO_Port GPIOC
#define HarfBridge_MD1C8_Pin GPIO_PIN_8
#define HarfBridge_MD1C8_GPIO_Port GPIOC
#define HarfBridge_MD2_Pin GPIO_PIN_9
#define HarfBridge_MD2_GPIO_Port GPIOC
#define HarfBridge_MD2A8_Pin GPIO_PIN_8
#define HarfBridge_MD2A8_GPIO_Port GPIOA
#define Arm_LED1_Pin GPIO_PIN_0
#define Arm_LED1_GPIO_Port GPIOD
#define Arm_LED2_Pin GPIO_PIN_1
#define Arm_LED2_GPIO_Port GPIOD
#define LED7seg_A_Pin GPIO_PIN_3
#define LED7seg_A_GPIO_Port GPIOD
#define LED7seg_B_Pin GPIO_PIN_4
#define LED7seg_B_GPIO_Port GPIOD
#define LED7seg_C_Pin GPIO_PIN_5
#define LED7seg_C_GPIO_Port GPIOD
#define LED7seg_D_Pin GPIO_PIN_6
#define LED7seg_D_GPIO_Port GPIOD
#define DAC_Zeroa_Pin GPIO_PIN_7
#define DAC_Zeroa_GPIO_Port GPIOD
#define DAC_Demp_Pin GPIO_PIN_4
#define DAC_Demp_GPIO_Port GPIOB
#define DAC_Mute_Pin GPIO_PIN_6
#define DAC_Mute_GPIO_Port GPIOB
#define z_Limit_Error_Pin GPIO_PIN_7
#define z_Limit_Error_GPIO_Port GPIOB
#define z_UpLimit_Pin GPIO_PIN_8
#define z_UpLimit_GPIO_Port GPIOB
#define z_BottomLimit_Soft_Pin GPIO_PIN_9
#define z_BottomLimit_Soft_GPIO_Port GPIOB
#define z_BottomLimit_Hard_Pin GPIO_PIN_0
#define z_BottomLimit_Hard_GPIO_Port GPIOE
#define y_BackLimit_Pin GPIO_PIN_1
#define y_BackLimit_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
