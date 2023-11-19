/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "button.h"
#include "software_timer.h"
#include "output.h"
#include "fsm_traffic_system.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern TIM_HandleTypeDef htim2;
extern int state;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_1
#define LED_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_2
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_3
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_4
#define BUTTON3_GPIO_Port GPIOA
#define RED1_Pin GPIO_PIN_5
#define RED1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_6
#define GREEN1_GPIO_Port GPIOA
#define YELLOW1_Pin GPIO_PIN_7
#define YELLOW1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_0
#define RED2_GPIO_Port GPIOB
#define GREEN2_Pin GPIO_PIN_1
#define GREEN2_GPIO_Port GPIOB
#define YELLOW2_Pin GPIO_PIN_2
#define YELLOW2_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_10
#define B_GPIO_Port GPIOB
#define C_Pin GPIO_PIN_11
#define C_GPIO_Port GPIOB
#define D_Pin GPIO_PIN_12
#define D_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_13
#define E_GPIO_Port GPIOB
#define F_Pin GPIO_PIN_14
#define F_GPIO_Port GPIOB
#define G_Pin GPIO_PIN_15
#define G_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_8
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_9
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_10
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_11
#define EN3_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_9
#define A_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
