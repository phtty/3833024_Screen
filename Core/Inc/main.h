/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
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
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

// SRAM地址位带区映射
#define BITBAND_SRAM(address, bit) (*(volatile uint32_t *)(0x22000000 + ((uint32_t)(address) - 0x20000000) * 0x20 + (bit) * 0x04))
// 外设地址位带区映射
#define BITBAND_PERIPH(address, bit) (*(volatile uint32_t *)(0x42000000 + ((uint32_t)(address) - 0x40000000) * 0x20 + (bit) * 0x04))

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define G4_Pin                GPIO_PIN_2
#define G4_GPIO_Port          GPIOE
#define B4_Pin                GPIO_PIN_3
#define B4_GPIO_Port          GPIOE
#define R5_Pin                GPIO_PIN_4
#define R5_GPIO_Port          GPIOE
#define G5_Pin                GPIO_PIN_5
#define G5_GPIO_Port          GPIOE
#define B5_Pin                GPIO_PIN_6
#define B5_GPIO_Port          GPIOE
#define R6_Pin                GPIO_PIN_13
#define R6_GPIO_Port          GPIOC
#define G6_Pin                GPIO_PIN_14
#define G6_GPIO_Port          GPIOC
#define B6_Pin                GPIO_PIN_15
#define B6_GPIO_Port          GPIOC
#define R7_Pin                GPIO_PIN_0
#define R7_GPIO_Port          GPIOF
#define G7_Pin                GPIO_PIN_1
#define G7_GPIO_Port          GPIOF
#define B7_Pin                GPIO_PIN_2
#define B7_GPIO_Port          GPIOF
#define R8_Pin                GPIO_PIN_3
#define R8_GPIO_Port          GPIOF
#define G8_Pin                GPIO_PIN_4
#define G8_GPIO_Port          GPIOF
#define B8_Pin                GPIO_PIN_5
#define B8_GPIO_Port          GPIOF
#define R9_Pin                GPIO_PIN_6
#define R9_GPIO_Port          GPIOF
#define G9_Pin                GPIO_PIN_7
#define G9_GPIO_Port          GPIOF
#define B9_Pin                GPIO_PIN_8
#define B9_GPIO_Port          GPIOF
#define R10_Pin               GPIO_PIN_9
#define R10_GPIO_Port         GPIOF
#define G10_Pin               GPIO_PIN_10
#define G10_GPIO_Port         GPIOF
#define B10_Pin               GPIO_PIN_0
#define B10_GPIO_Port         GPIOC
#define W25QXX_CS_Pin         GPIO_PIN_1
#define W25QXX_CS_GPIO_Port   GPIOB
#define RS232_TX1_Pin         GPIO_PIN_10
#define RS232_TX1_GPIO_Port   GPIOB
#define RS232_RX1_Pin         GPIO_PIN_11
#define RS232_RX1_GPIO_Port   GPIOB
#define LED_Pin               GPIO_PIN_9
#define LED_GPIO_Port         GPIOD
#define RS232_TX2_Pin         GPIO_PIN_6
#define RS232_TX2_GPIO_Port   GPIOC
#define RS232_RX2_Pin         GPIO_PIN_7
#define RS232_RX2_GPIO_Port   GPIOC
#define RS485_TX_Pin          GPIO_PIN_9
#define RS485_TX_GPIO_Port    GPIOA
#define RS485_RX_Pin          GPIO_PIN_10
#define RS485_RX_GPIO_Port    GPIOA
#define OE_Pin                GPIO_PIN_0
#define OE_GPIO_Port          GPIOD
#define CLK_Pin               GPIO_PIN_1
#define CLK_GPIO_Port         GPIOD
#define LAT_Pin               GPIO_PIN_3
#define LAT_GPIO_Port         GPIOD
#define ADDR_A_Pin            GPIO_PIN_4
#define ADDR_A_GPIO_Port      GPIOD
#define ADDR_B_Pin            GPIO_PIN_5
#define ADDR_B_GPIO_Port      GPIOD
#define ADDR_C_Pin            GPIO_PIN_6
#define ADDR_C_GPIO_Port      GPIOD
#define ADDR_D_Pin            GPIO_PIN_7
#define ADDR_D_GPIO_Port      GPIOD
#define R1_Pin                GPIO_PIN_9
#define R1_GPIO_Port          GPIOG
#define G1_Pin                GPIO_PIN_10
#define G1_GPIO_Port          GPIOG
#define B1_Pin                GPIO_PIN_12
#define B1_GPIO_Port          GPIOG
#define R2_Pin                GPIO_PIN_15
#define R2_GPIO_Port          GPIOG
#define W25QXX_CLK_Pin        GPIO_PIN_3
#define W25QXX_CLK_GPIO_Port  GPIOB
#define W25QXX_MISO_Pin       GPIO_PIN_4
#define W25QXX_MISO_GPIO_Port GPIOB
#define W25QXX_MOSI_Pin       GPIO_PIN_5
#define W25QXX_MOSI_GPIO_Port GPIOB
#define G2_Pin                GPIO_PIN_6
#define G2_GPIO_Port          GPIOB
#define B2_Pin                GPIO_PIN_7
#define B2_GPIO_Port          GPIOB
#define R3_Pin                GPIO_PIN_8
#define R3_GPIO_Port          GPIOB
#define G3_Pin                GPIO_PIN_9
#define G3_GPIO_Port          GPIOB
#define B3_Pin                GPIO_PIN_0
#define B3_GPIO_Port          GPIOE
#define R4_Pin                GPIO_PIN_1
#define R4_GPIO_Port          GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
