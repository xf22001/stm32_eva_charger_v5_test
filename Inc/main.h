/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#define rey1_Pin GPIO_PIN_4
#define rey1_GPIO_Port GPIOA
#define rey2_Pin GPIO_PIN_5
#define rey2_GPIO_Port GPIOA
#define rejy3_Pin GPIO_PIN_6
#define rejy3_GPIO_Port GPIOA
#define rey4_Pin GPIO_PIN_7
#define rey4_GPIO_Port GPIOA
#define rey5_Pin GPIO_PIN_4
#define rey5_GPIO_Port GPIOC
#define rey6_Pin GPIO_PIN_5
#define rey6_GPIO_Port GPIOC
#define rey7_Pin GPIO_PIN_0
#define rey7_GPIO_Port GPIOB
#define rey8_Pin GPIO_PIN_1
#define rey8_GPIO_Port GPIOB
#define rey9_Pin GPIO_PIN_7
#define rey9_GPIO_Port GPIOE
#define rejy10_Pin GPIO_PIN_8
#define rejy10_GPIO_Port GPIOE
#define rey11_Pin GPIO_PIN_9
#define rey11_GPIO_Port GPIOE
#define rey12_Pin GPIO_PIN_10
#define rey12_GPIO_Port GPIOE
#define rey13_Pin GPIO_PIN_11
#define rey13_GPIO_Port GPIOE
#define rey14_Pin GPIO_PIN_12
#define rey14_GPIO_Port GPIOE
#define rey15_Pin GPIO_PIN_13
#define rey15_GPIO_Port GPIOE
#define rey16_Pin GPIO_PIN_14
#define rey16_GPIO_Port GPIOE
#define rey17_Pin GPIO_PIN_15
#define rey17_GPIO_Port GPIOE
#define rey18_Pin GPIO_PIN_8
#define rey18_GPIO_Port GPIOD
#define rey19_Pin GPIO_PIN_9
#define rey19_GPIO_Port GPIOD
#define rey20_Pin GPIO_PIN_10
#define rey20_GPIO_Port GPIOD
#define rey21_Pin GPIO_PIN_11
#define rey21_GPIO_Port GPIOD
#define rey22_Pin GPIO_PIN_12
#define rey22_GPIO_Port GPIOD
#define ledcpu_Pin GPIO_PIN_15
#define ledcpu_GPIO_Port GPIOA
#define can_int0_Pin GPIO_PIN_6
#define can_int0_GPIO_Port GPIOB
#define can_int1_Pin GPIO_PIN_7
#define can_int1_GPIO_Port GPIOB
#define can_cs_Pin GPIO_PIN_8
#define can_cs_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
