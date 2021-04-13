/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "can.h"
#include "dma.h"
#include "i2s.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "buttons.h"
#include "limitswitches.h"
#include "toggleswitches.h"
#include "dipswitches.h"
#include "encoder.h"
#include "led7seg.h"
#include "motor.h"
#include <math.h>
#include <stdio.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define X_ENC_LIMIT (77680)
#define Y_ENC_LIMIT (58000) // マイナス
#define Z_ENC_LIMIT (160000) // マイナス

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static uint16_t adcbuff[6]; // 0~2:xyzLimit 3:XY速度 4:開閉速度 6番目はRangeFinder
static uint8_t count = 0;
static int32_t x_enc = 0, y_enc = 0, z_enc = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Rot90deg_Stepper(float rpm);
void Update_Enc(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_CAN_Init();
  MX_I2S3_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  MX_USART2_UART_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Transmit(&huart2, "START\r\n", 7, 0xFFFF);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);

  HAL_GPIO_WritePin(Arm_LED1_GPIO_Port, Arm_LED1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(Arm_LED2_GPIO_Port, Arm_LED2_Pin, GPIO_PIN_SET);

  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);

  Display_led7seg(count);

  /* ADCサンプリング･DMA転送開始 */
  HAL_ADC_Start_DMA(&hadc1, adcbuff, 6);

//  while (1) {
//      uint8_t buff[40];
//      HAL_ADC_Start_DMA(&hadc1, adcbuff, 6);
//      sprintf(buff, "%4d %4d %4d %4d %4d %4d ", adcbuff[0], adcbuff[1], adcbuff[2], adcbuff[3], adcbuff[4], adcbuff[5]);
//      HAL_UART_Transmit(&huart2, buff, 30, 0xFFFF); // 各ADCの値
//      sprintf(buff, "x%6d y%6d z%6d\r\n", x_enc, y_enc, z_enc);
//      HAL_UART_Transmit(&huart2, buff, 25, 0xFFFF); // 各encの値
////      Display_led7seg(10);
////      HAL_Delay(5);
////      Display_led7seg(13);
////      HAL_Delay(5);
//      Update_Enc();
//  }

  /* タイマ割り込み開始 */
  HAL_TIM_Base_Start_IT(&htim6);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  /* テスト用 */
	  uint8_t buff[40];
//	  sprintf(buff, "%4d %4d %4d %4d %4d\r\n", adcbuff[0], adcbuff[1], adcbuff[2], adcbuff[3], adcbuff[4]);
//	  HAL_UART_Transmit(&huart2, buff, 26, 0xFFFF); // 各ADCの値
	  sprintf(buff, "x%6d y%6d z%7d\r\n", x_enc,
	                                         y_enc,
	                                         z_enc);
	  HAL_UART_Transmit(&huart2, buff, 26, 0xFFFF); // 各encの値
//	  sprintf(buff, "xL%6d yL%6d zL%7d\r\n", (int)(X_ENC_LIMIT / 4095.0 * adcbuff[0]),
//	                                         (int)(Y_ENC_LIMIT / 4095.0 * adcbuff[1]),
//	                                         (int)(Z_ENC_LIMIT / 4095.0 * adcbuff[2]));
//	  HAL_UART_Transmit(&huart2, buff, 29, 0xFFFF); // 各encの値
      if (x_enc >= X_ENC_LIMIT * (adcbuff[0] / 4095.0f)) {
          HAL_UART_Transmit(&huart2, "A\r\n", 3, 0xFFFF); // 各encの値
      }
//	  if(isPressed_x_LeftLimit())
//		  HAL_UART_Transmit(&huart2, "xL", 2, 0xFFFF);
//	  if(isPressed_x_RightLimit())
//		  HAL_UART_Transmit(&huart2, "xR", 2, 0xFFFF);
//	  if(isPressed_y_BackLimit())
//		  HAL_UART_Transmit(&huart2, "yB", 2, 0xFFFF);
//	  if(isPressed_y_FrontLimit())
//		  HAL_UART_Transmit(&huart2, "yF", 2, 0xFFFF);
//	  if(isPressed_z_UpLimit())
//		  HAL_UART_Transmit(&huart2, "zU", 2, 0xFFFF);
//	  if(isPressed_z_Limit_Error())
//		  HAL_UART_Transmit(&huart2, "zE", 2, 0xFFFF);
//	  if(isPressed_z_BottomLimit_Hard())
//		  HAL_UART_Transmit(&huart2, "zBH", 3, 0xFFFF);
//	  if(isPressed_z_BottomLimit_Soft())
//		  HAL_UART_Transmit(&huart2, "zBS", 3, 0xFFFF);
//	  if(isPressed_x_PushButton())
//		  HAL_UART_Transmit(&huart2, "xP", 2, 0xFFFF);
//	  if(isPressed_y_PushButton())
//		  HAL_UART_Transmit(&huart2, "yP", 2, 0xFFFF);
//	  if(isHigh_DIP_SW1())
//		  HAL_UART_Transmit(&huart2, "D1", 2, 0xFFFF);
//	  if(isHigh_DIP_SW2())
//		  HAL_UART_Transmit(&huart2, "D2", 2, 0xFFFF);
//	  if(isHigh_DIP_SW3())
//		  HAL_UART_Transmit(&huart2, "D3", 2, 0xFFFF);
//	  if(isHigh_Toggle1())
//		  HAL_UART_Transmit(&huart2, "T1", 2, 0xFFFF);
//	  if(isHigh_Toggle2())
//		  HAL_UART_Transmit(&huart2, "T2", 2, 0xFFFF);
//	  if(isHigh_Toggle3())
//		  HAL_UART_Transmit(&huart2, "T3", 2, 0xFFFF);

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC|RCC_PERIPHCLK_I2S3;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  PeriphClkInit.I2s3ClockSelection = RCC_I2S3CLKSOURCE_SYSCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
// Yプラスで手前
// Xプラスで右
// Zプラスで上
// タイマ割り込み処理 TIM6を使用 100Hzか50Hzのはず
enum phase { WAIT_X, MOVE_X, WAIT_Y, MOVE_Y, WAIT_OPEN, OPEN, WAIT_DOWN, DOWN,
    WAIT_PICK, PICK, WAIT_UP, UP, WAIT_MOVE3, MOVE3, RELEASE, WAIT_CLOSE, CLOSE, WAIT_FINAL};
static uint8_t phase = WAIT_X;
static uint32_t frame_cnt = 0;
static uint32_t timeCount = 0;
static bool isnotreset_coin = false; // コインの連続投入をカウントするために、一度コインが離れるまでtrue
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim6)
    {
        Update_Enc();
//        if (isPressed_z_Limit_Error()) { // TODO:
//            // エラー時 停止
//            Set_Motor_X(0);
//            Set_Motor_Y(0);
//            Set_Motor_Z(0);
//            Set_Motor_Half_1(0);
//            Set_Motor_Half_2(0);
//            while(1);
//        }

        if (phase == WAIT_X) {
            if (frame_cnt > 0) { // 何もしない
                if (!isPressed_LED7seg_CountUP() && !isPressed_LED7seg_CountDown()) {
                    frame_cnt = 0;
                }
            }
            else if (isPressed_LED7seg_CountUP() || isPressed_CoinSelecter_100()) {
                frame_cnt++; // オーバーフローしそう
                if (count < 9) {
                    count++;
                }
            }
            else if (isPressed_LED7seg_CountDown()) {
                frame_cnt++;
                count--;
            }

            // 残りプレイ回数を表示
            Display_led7seg(count);

            if (count > 0 && isPressed_x_PushButton()) {
                phase = MOVE_X;
                frame_cnt = 0;
            }
        }
        else if (phase == MOVE_X) {
            Set_Motor_X(80 * (adcbuff[3] / 4095.0f) + 1); // Xプラスで右
            if (isPressed_x_RightLimit() || x_enc >= X_ENC_LIMIT / 4095.0 * adcbuff[0] || !isPressed_x_PushButton()) {
                Set_Motor_X(0);
                phase = WAIT_Y;
            }
        }
        else if (phase == WAIT_Y) {
            if (isPressed_y_PushButton()) {
                phase = MOVE_Y;
            }
        }
        else if (phase == MOVE_Y) {
            Set_Motor_Y(-80 * (adcbuff[3] / 4095.0f) - 1); // Yプラスで手前
            if (isPressed_y_BackLimit() || y_enc <= -Y_ENC_LIMIT / 4095.0 * adcbuff[1] || !isPressed_y_PushButton()) {
                Set_Motor_Y(0);
                phase = WAIT_OPEN;
            }
        }
        else if (phase == WAIT_OPEN) {
            // ただの時間待ち
            timeCount++;
            if (timeCount > 100) {
                timeCount = 0;
                phase = OPEN;
            }
        }
        else if (phase == OPEN) {
            // アーム開く
            Rot90deg_Stepper(80 * (adcbuff[4] / 4095.0f) + 1);
            phase = WAIT_DOWN;
        }
        else if (phase == WAIT_DOWN) {
            // ただの時間待ち
            timeCount++;
            if (timeCount > 100) {
                timeCount = 0;
                phase = DOWN;
            }
        }
        else if (phase == DOWN) {
            Set_Motor_Z(-100);
            if (isPressed_z_BottomLimit_Soft() || z_enc <= -Z_ENC_LIMIT * adcbuff[2] / 4095.0) {
                Set_Motor_Z(0);
                phase = WAIT_PICK;
            }
        }
        else if (phase == WAIT_PICK) {
            // ただの時間待ち
            timeCount++;
            if (timeCount > 200) {
                timeCount = 0;
                phase = PICK;
            }
        }
        else if (phase == PICK) {
            // アーム閉じる
            Rot90deg_Stepper(80 * (adcbuff[4] / 4095.0f) + 1);
            phase = WAIT_UP;
        }
        else if (phase == WAIT_UP) {
            // ただの時間待ち
            timeCount++;
            if (timeCount > 100) {
                timeCount = 0;
                phase = UP;
            }
        }
        else if (phase == UP) {
            Set_Motor_Z(100);

            if (isPressed_z_UpLimit()) { //TODO:
                Set_Motor_Z(0);
                timeCount = 0;
                phase = WAIT_MOVE3;
            }

//            timeCount++;
//            if (timeCount > 400) { // TODO:今は時間待ちになっている
//                Set_Motor_Z(0);
//                timeCount = 0;
//                phase = WAIT_MOVE3;
//            }
//                phase = WAIT_MOVE3;
//            }
        }
        else if (phase == WAIT_MOVE3) {
            // ただの時間待ち
            timeCount++;
            if (timeCount > 100) {
                timeCount = 0;
                phase = MOVE3;
            }
        }
        else if (phase == MOVE3) {
            if (isPressed_y_FrontLimit()) {
                Set_Motor_Y(0);
            }
            else {
                Set_Motor_Y(80 * (adcbuff[3] / 4095.0f) + 1);
            }
            if (isPressed_x_LeftLimit()) {
                Set_Motor_X(0);
            }
            else {
                Set_Motor_X(-80 * (adcbuff[3] / 4095.0f) - 1);
            }

            if (isPressed_y_FrontLimit() && isPressed_x_LeftLimit()) {
                // モーター止める
                Set_Motor_X(0);
                Set_Motor_Y(0);
                // 待つ
                timeCount++;
                if (timeCount > 100) {
                    timeCount = 0;
                    count--;
                    phase = RELEASE;
                }
            }
        }
        else if (phase == RELEASE) {
            // アーム開く
            Rot90deg_Stepper(80 * (adcbuff[4] / 4095.0f) + 1);
            phase = CLOSE;
        }
        else if(phase == WAIT_CLOSE) {
            timeCount++;
            if (timeCount > 200) {
                timeCount = 0;
                phase = CLOSE;//162422
            }
        }
        else if (phase == CLOSE) {
            // アーム閉じる
            Rot90deg_Stepper(80 * (adcbuff[4] / 4095.0f) + 1);
            phase = WAIT_FINAL;
        }
        else if (phase == WAIT_FINAL) {
            timeCount++;
            if (timeCount > 200) {
                timeCount = 0;
                phase = WAIT_X; // 最初に戻る
            }
        }
    }
}

#define STEP_DEG (7.5)
void Rot90deg_Stepper(float rpm) {
    uint32_t delay_ms = 60000 / (360 / STEP_DEG) / 4 / rpm;
    for (uint32_t i = 0; i < 12*7.5; i++) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
        HAL_Delay(delay_ms);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
        HAL_Delay(delay_ms);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
        HAL_Delay(delay_ms);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
        HAL_Delay(delay_ms);
    }
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
}

void Update_Enc(void) {
    if (isPressed_x_LeftLimit()) {
        x_enc = 0;
        Set_x_Enc(0);
    }
    else if (isPressed_x_RightLimit()) {
        x_enc = X_ENC_LIMIT;
        Set_x_Enc(0);
    }
    else {
        x_enc += Get_x_Enc();
        Set_x_Enc(0);
    }

    if (isPressed_y_FrontLimit()) {
        y_enc = 0;
        Set_y_Enc(0);
    }
    else if (isPressed_y_BackLimit()) {
        y_enc = -Y_ENC_LIMIT;
        Set_y_Enc(0);
    }
    else {
        y_enc += Get_y_Enc();
        Set_y_Enc(0);
    }

    if (isPressed_z_UpLimit()) {
        z_enc = 0;
        Set_z_Enc(0);
    }
//    else if (isPressed_z_UpLimit()) {
//
//    }
    else {
        z_enc += Get_z_Enc();
        Set_z_Enc(0);
    }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
