/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, M_L2_DIR_OUT2_Pin|M_L2_DIR_OUT1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, M_L1_DIR_OUT2_Pin|M_L1_DIR_OUT1_Pin|ULTRASONIC_TRIG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, M_R2_DIR_OUT2_Pin|M_R2_DIR_OUT1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(M_R1_DIR_OUT1_GPIO_Port, M_R1_DIR_OUT1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(M_R1_DIR_OUT2_GPIO_Port, M_R1_DIR_OUT2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : M_L2_DIR_OUT2_Pin M_L2_DIR_OUT1_Pin */
  GPIO_InitStruct.Pin = M_L2_DIR_OUT2_Pin|M_L2_DIR_OUT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : V_L2_DIR_Pin */
  GPIO_InitStruct.Pin = V_L2_DIR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(V_L2_DIR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : M_L1_DIR_OUT2_Pin M_L1_DIR_OUT1_Pin ULTRASONIC_TRIG_Pin */
  GPIO_InitStruct.Pin = M_L1_DIR_OUT2_Pin|M_L1_DIR_OUT1_Pin|ULTRASONIC_TRIG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : V_L1_DIR_Pin */
  GPIO_InitStruct.Pin = V_L1_DIR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(V_L1_DIR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : P_L4_Pin */
  GPIO_InitStruct.Pin = P_L4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(P_L4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : P_L3_Pin P_L2_Pin P_L1_Pin P_R1_Pin
                           P_R2_Pin P_R3_Pin */
  GPIO_InitStruct.Pin = P_L3_Pin|P_L2_Pin|P_L1_Pin|P_R1_Pin
                          |P_R2_Pin|P_R3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : V_R1_DIR_Pin */
  GPIO_InitStruct.Pin = V_R1_DIR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(V_R1_DIR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : P_MID_Pin */
  GPIO_InitStruct.Pin = P_MID_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(P_MID_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ULTRASONIC_ECHO_Pin */
  GPIO_InitStruct.Pin = ULTRASONIC_ECHO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ULTRASONIC_ECHO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : M_R2_DIR_OUT2_Pin M_R2_DIR_OUT1_Pin */
  GPIO_InitStruct.Pin = M_R2_DIR_OUT2_Pin|M_R2_DIR_OUT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pin : M_R1_DIR_OUT1_Pin */
  GPIO_InitStruct.Pin = M_R1_DIR_OUT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(M_R1_DIR_OUT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : M_R1_DIR_OUT2_Pin */
  GPIO_InitStruct.Pin = M_R1_DIR_OUT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(M_R1_DIR_OUT2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PF15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pin : P_R4_Pin */
  GPIO_InitStruct.Pin = P_R4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(P_R4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : V_R2_DIR_Pin */
  GPIO_InitStruct.Pin = V_R2_DIR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(V_R2_DIR_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI3_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
