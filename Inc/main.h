/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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
#define M_L2_DIR_OUT2_Pin GPIO_PIN_2
#define M_L2_DIR_OUT2_GPIO_Port GPIOE
#define V_L2_DIR_Pin GPIO_PIN_1
#define V_L2_DIR_GPIO_Port GPIOE
#define PULSE_COUNT_L1_Pin GPIO_PIN_15
#define PULSE_COUNT_L1_GPIO_Port GPIOA
#define M_L2_DIR_OUT1_Pin GPIO_PIN_4
#define M_L2_DIR_OUT1_GPIO_Port GPIOE
#define PWM_L1_Pin GPIO_PIN_5
#define PWM_L1_GPIO_Port GPIOE
#define M_L1_DIR_OUT2_Pin GPIO_PIN_11
#define M_L1_DIR_OUT2_GPIO_Port GPIOG
#define M_L1_DIR_OUT1_Pin GPIO_PIN_10
#define M_L1_DIR_OUT1_GPIO_Port GPIOG
#define V_L1_DIR_Pin GPIO_PIN_12
#define V_L1_DIR_GPIO_Port GPIOA
#define PULSE_COUNT_L2_Pin GPIO_PIN_6
#define PULSE_COUNT_L2_GPIO_Port GPIOI
#define P_L4_Pin GPIO_PIN_3
#define P_L4_GPIO_Port GPIOD
#define P_L3_Pin GPIO_PIN_15
#define P_L3_GPIO_Port GPIOH
#define P_L2_Pin GPIO_PIN_13
#define P_L2_GPIO_Port GPIOH
#define P_L1_Pin GPIO_PIN_14
#define P_L1_GPIO_Port GPIOH
#define PULSE_COUNT_R1_Pin GPIO_PIN_8
#define PULSE_COUNT_R1_GPIO_Port GPIOA
#define V_R1_DIR_Pin GPIO_PIN_8
#define V_R1_DIR_GPIO_Port GPIOC
#define ULTRASONIC_TRIG_Pin GPIO_PIN_6
#define ULTRASONIC_TRIG_GPIO_Port GPIOG
#define PWM_L2_Pin GPIO_PIN_7
#define PWM_L2_GPIO_Port GPIOF
#define P_R1_Pin GPIO_PIN_12
#define P_R1_GPIO_Port GPIOH
#define P_MID_Pin GPIO_PIN_5
#define P_MID_GPIO_Port GPIOG
#define ULTRASONIC_ECHO_Pin GPIO_PIN_3
#define ULTRASONIC_ECHO_GPIO_Port GPIOG
#define ULTRASONIC_ECHO_EXTI_IRQn EXTI3_IRQn
#define M_R2_DIR_OUT2_Pin GPIO_PIN_10
#define M_R2_DIR_OUT2_GPIO_Port GPIOF
#define M_R2_DIR_OUT1_Pin GPIO_PIN_9
#define M_R2_DIR_OUT1_GPIO_Port GPIOF
#define PWM_R2_Pin GPIO_PIN_8
#define PWM_R2_GPIO_Port GPIOF
#define P_R2_Pin GPIO_PIN_11
#define P_R2_GPIO_Port GPIOH
#define P_R3_Pin GPIO_PIN_10
#define P_R3_GPIO_Port GPIOH
#define PULSE_COUNT_R2_Pin GPIO_PIN_6
#define PULSE_COUNT_R2_GPIO_Port GPIOA
#define M_R1_DIR_OUT1_Pin GPIO_PIN_5
#define M_R1_DIR_OUT1_GPIO_Port GPIOA
#define M_R1_DIR_OUT2_Pin GPIO_PIN_5
#define M_R1_DIR_OUT2_GPIO_Port GPIOC
#define P_R4_Pin GPIO_PIN_13
#define P_R4_GPIO_Port GPIOB
#define PWM_R1_Pin GPIO_PIN_7
#define PWM_R1_GPIO_Port GPIOA
#define V_R2_DIR_Pin GPIO_PIN_11
#define V_R2_DIR_GPIO_Port GPIOF

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
