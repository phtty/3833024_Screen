/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tim.h"
#include "spi.h"
#include "w25qxx.h"
#include "hub75.h"
#include "render.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
osThreadId_t HalfSecTaskHandle;
const osThreadAttr_t HalfSecTask_attributes = {
    .name       = "HalfSecTask",
    .stack_size = 128 * 4,
    .priority   = (osPriority_t)osPriorityNormal,
};

osThreadId_t PointTestTaskHandle;
const osThreadAttr_t PointTestTask_attributes = {
    .name       = "PointTestTask",
    .stack_size = 1024 * 4,
    .priority   = (osPriority_t)osPriorityAboveNormal,
};

osThreadId_t RefreshTaskHandle;
const osThreadAttr_t RefreshTask_attributes = {
    .name       = "RefreshTask",
    .stack_size = 512 * 4,
    .priority   = (osPriority_t)osPriorityAboveNormal,
};
/* USER CODE END Variables */
/* Definitions for initTask */
osThreadId_t initTaskHandle;
const osThreadAttr_t initTask_attributes = {
    .name       = "initTask",
    .stack_size = 256 * 4,
    .priority   = (osPriority_t)osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void HalfSecTask(void *argument);
void PointTestTask(void *argument);
void RefreshTask(void *argument);
/* USER CODE END FunctionPrototypes */

void InitailizeTask(void *argument);

extern void MX_LWIP_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    /* USER CODE END RTOS_QUEUES */

    /* Create the thread(s) */
    /* creation of initTask */
    initTaskHandle = osThreadNew(InitailizeTask, NULL, &initTask_attributes);

    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
    /* USER CODE END RTOS_THREADS */

    /* USER CODE BEGIN RTOS_EVENTS */
    /* add events, ... */
    /* USER CODE END RTOS_EVENTS */
}

/* USER CODE BEGIN Header_InitailizeTask */
/**
 * @brief  Function implementing the initTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_InitailizeTask */
void InitailizeTask(void *argument)
{
    /* init code for LWIP */
    MX_LWIP_Init();
    /* USER CODE BEGIN InitailizeTask */
    __HAL_DBGMCU_FREEZE_TIM3();
    __HAL_DBGMCU_FREEZE_TIM4();
    init_hub75();
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start_IT(&htim4);

    HalfSecTaskHandle   = osThreadNew(HalfSecTask, NULL, &HalfSecTask_attributes);
    PointTestTaskHandle = osThreadNew(PointTestTask, NULL, &PointTestTask_attributes);
    // RefreshTaskHandle = osThreadNew(RefreshTask, NULL, &RefreshTask_attributes);

    BSP_W25Qx_Init(&hw25q64, &hspi1);

    // RenderString(0, 0, (uint8_t *)"ab²âc»»ÐÐ", strlen("ab²âc»»ÐÐ"), green, font_24, font_ht);

    osThreadExit();
    /* Infinite loop */
    for (;;) {
        osDelay(1);
    }
    /* USER CODE END InitailizeTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void HalfSecTask(void *argument)
{
    for (;;) {
        HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        osDelay(500);
    }
}

void RefreshTask(void *argument)
{
    uint32_t refresh_flag = 0;

    for (;;) {
        refresh_flag = osThreadFlagsWait(0x01, osFlagsWaitAny, osWaitForever);
        if (refresh_flag)
            convert_pixelmap();
    }
}

void PointTestTask(void *argument)
{
    // HAL_TIM_Base_Stop_IT(&htim3);
    point_order_test(black, CHANNEL_PIXEL_NUM / 2, 0);

    for (;;) {
        for (int i = 0; i < DISRAM_SIZE; i++) {
            pixel_map[i] = green;

            convert_pixelmap();
            osDelay(50);

            pixel_map[i] = black;
        }

        // point_order_test(green, 1, 0);
        // osDelay(500);
    }
}
/* USER CODE END Application */
