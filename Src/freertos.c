/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "../BSP/Track.h"
#include "../BSP/PID.h"
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
extern float ultrasonicValue;	//距离单位：厘�??

extern int speed,speed_dif,dir_LR;				//基本速度、差速�?�方�???
extern int status;
/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId TrackHandle;
osThreadId MotorControlHandle;
osThreadId DistanceHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void TrackFunc(void const * argument);
void MotorControlFunc(void const * argument);
void DistanceFunc(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
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
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of Track */
  osThreadDef(Track, TrackFunc, osPriorityRealtime, 0, 128);
  TrackHandle = osThreadCreate(osThread(Track), NULL);

  /* definition and creation of MotorControl */
  osThreadDef(MotorControl, MotorControlFunc, osPriorityHigh, 0, 128);
  MotorControlHandle = osThreadCreate(osThread(MotorControl), NULL);

  /* definition and creation of Distance */
  osThreadDef(Distance, DistanceFunc, osPriorityAboveNormal, 0, 128);
  DistanceHandle = osThreadCreate(osThread(Distance), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
	  printf("System running...\n");
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_TrackFunc */
/**
* @brief Function implementing the Track thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TrackFunc */
void TrackFunc(void const * argument)
{
  /* USER CODE BEGIN TrackFunc */
  /* Infinite loop */
  for(;;)
  {
	  if(ultrasonicValue>30)
	  {
		  FollowLine();
	  }
	  osDelay(50);
  }
  /* USER CODE END TrackFunc */
}

/* USER CODE BEGIN Header_MotorControlFunc */
/**
* @brief Function implementing the MotorControl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MotorControlFunc */
void MotorControlFunc(void const * argument)
{
  /* USER CODE BEGIN MotorControlFunc */
  /* Infinite loop */
  for(;;)
  {
	  if(ultrasonicValue>45)
	  {
		  FollowLine();
		  speed_dif=PID_Control(status);
		  //printf("speed_dif=%d\n",speed_dif);
		  //电机L1
		  HAL_GPIO_WritePin(M_L1_DIR_OUT1_GPIO_Port, M_L1_DIR_OUT1_Pin, 0);
		  HAL_GPIO_WritePin(M_L1_DIR_OUT2_GPIO_Port, M_L1_DIR_OUT2_Pin,1);
		  __HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_1, speed+speed_dif);
		  //电机R1
		  HAL_GPIO_WritePin(M_R1_DIR_OUT1_GPIO_Port, M_R1_DIR_OUT1_Pin, 1);
		  HAL_GPIO_WritePin(M_R1_DIR_OUT2_GPIO_Port, M_R1_DIR_OUT2_Pin,0);
		  __HAL_TIM_SetCompare(&htim14, TIM_CHANNEL_1,speed-speed_dif);
		  //电机L2
		  HAL_GPIO_WritePin(M_L2_DIR_OUT1_GPIO_Port, M_L2_DIR_OUT1_Pin, 0);
		  HAL_GPIO_WritePin(M_L2_DIR_OUT2_GPIO_Port, M_L2_DIR_OUT2_Pin,1);
		  __HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, speed+speed_dif);
			//电机R2
		  HAL_GPIO_WritePin(M_R2_DIR_OUT1_GPIO_Port, M_R2_DIR_OUT1_Pin, 1);
		  HAL_GPIO_WritePin(M_R2_DIR_OUT2_GPIO_Port, M_R2_DIR_OUT2_Pin,0);
		  __HAL_TIM_SetCompare(&htim13, TIM_CHANNEL_1, speed-speed_dif);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(M_L1_DIR_OUT1_GPIO_Port, M_L1_DIR_OUT1_Pin, 0);
		  HAL_GPIO_WritePin(M_L1_DIR_OUT2_GPIO_Port, M_L1_DIR_OUT2_Pin,1);
		  __HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_1, 0);
		  //电机R1
		  HAL_GPIO_WritePin(M_R1_DIR_OUT1_GPIO_Port, M_R1_DIR_OUT1_Pin, 1);
		  HAL_GPIO_WritePin(M_R1_DIR_OUT2_GPIO_Port, M_R1_DIR_OUT2_Pin,0);
		  __HAL_TIM_SetCompare(&htim14, TIM_CHANNEL_1,0);
		  //电机L2
		  HAL_GPIO_WritePin(M_L2_DIR_OUT1_GPIO_Port, M_L2_DIR_OUT1_Pin, 0);
		  HAL_GPIO_WritePin(M_L2_DIR_OUT2_GPIO_Port, M_L2_DIR_OUT2_Pin,1);
		  __HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 0);
			//电机R2
		  HAL_GPIO_WritePin(M_R2_DIR_OUT1_GPIO_Port, M_R2_DIR_OUT1_Pin, 1);
		  HAL_GPIO_WritePin(M_R2_DIR_OUT2_GPIO_Port, M_R2_DIR_OUT2_Pin,0);
		  __HAL_TIM_SetCompare(&htim13, TIM_CHANNEL_1, 0);
	  }
	  osDelay(50);

  }
  /* USER CODE END MotorControlFunc */
}

/* USER CODE BEGIN Header_DistanceFunc */
/**
* @brief Function implementing the Distance thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_DistanceFunc */
void DistanceFunc(void const * argument)
{
  /* USER CODE BEGIN DistanceFunc */
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_WritePin(ULTRASONIC_TRIG_GPIO_Port, ULTRASONIC_TRIG_Pin, GPIO_PIN_SET);
	  osDelay(1);
	  HAL_GPIO_WritePin(ULTRASONIC_TRIG_GPIO_Port, ULTRASONIC_TRIG_Pin, GPIO_PIN_RESET);
	  osDelay(200);
  }
  /* USER CODE END DistanceFunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
