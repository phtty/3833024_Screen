/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, G4_Pin|B4_Pin|R5_Pin|G5_Pin
                          |B5_Pin|B3_Pin|R4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, R6_Pin|G6_Pin|B6_Pin|B10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, R7_Pin|G7_Pin|B7_Pin|R8_Pin
                          |G8_Pin|B8_Pin|R9_Pin|G9_Pin
                          |B9_Pin|R10_Pin|G10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, W25QXX_CS_Pin|G2_Pin|B2_Pin|R3_Pin
                          |G3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LED_Pin|OE_Pin|CLK_Pin|LAT_Pin
                          |ADDR_A_Pin|ADDR_B_Pin|ADDR_C_Pin|ADDR_D_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, R1_Pin|G1_Pin|B1_Pin|R2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : G4_Pin B4_Pin R5_Pin G5_Pin
                           B5_Pin B3_Pin R4_Pin */
  GPIO_InitStruct.Pin = G4_Pin|B4_Pin|R5_Pin|G5_Pin
                          |B5_Pin|B3_Pin|R4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : R6_Pin G6_Pin B6_Pin B10_Pin */
  GPIO_InitStruct.Pin = R6_Pin|G6_Pin|B6_Pin|B10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : R7_Pin G7_Pin B7_Pin R8_Pin
                           G8_Pin B8_Pin R9_Pin G9_Pin
                           B9_Pin R10_Pin G10_Pin */
  GPIO_InitStruct.Pin = R7_Pin|G7_Pin|B7_Pin|R8_Pin
                          |G8_Pin|B8_Pin|R9_Pin|G9_Pin
                          |B9_Pin|R10_Pin|G10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : W25QXX_CS_Pin G2_Pin B2_Pin R3_Pin
                           G3_Pin */
  GPIO_InitStruct.Pin = W25QXX_CS_Pin|G2_Pin|B2_Pin|R3_Pin
                          |G3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PE10 PE11 PE12 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_Pin OE_Pin CLK_Pin LAT_Pin
                           ADDR_A_Pin ADDR_B_Pin ADDR_C_Pin ADDR_D_Pin */
  GPIO_InitStruct.Pin = LED_Pin|OE_Pin|CLK_Pin|LAT_Pin
                          |ADDR_A_Pin|ADDR_B_Pin|ADDR_C_Pin|ADDR_D_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : R1_Pin G1_Pin B1_Pin R2_Pin */
  GPIO_InitStruct.Pin = R1_Pin|G1_Pin|B1_Pin|R2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
