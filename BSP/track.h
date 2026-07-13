#ifndef BSP_Track_H_
#define BSP_Track_H_
#include "gpio.h"
#define DIR_LEFT 0 //需行进方向
#define DIR_RIGHT 1
#define DIR_STRAIGHT 2
/*
* ----------------------------------------------------------------------------------
* | bit0 | bit1 | bit2 | bit3 | bit4 | bit5 | bit6 | bit7 | bit8 |
* |--------------------------------------------------------------------------------|
* |left1 |left2 |left3 |left4 |right1 |right2 |right3 |right4 |middle |
* ---------------------------------------------------------------------------------|
* | phototube_vale |
* ----------------------------------------------------------------------------------
* */
typedef union {
struct {
	unsigned int left1 : 1;
	unsigned int left2 : 1;
	unsigned int left3 : 1;
	unsigned int left4 : 1;
	unsigned int right1: 1;
	unsigned int right2: 1;
	unsigned int right3: 1;
	unsigned int right4: 1;
	unsigned int middle: 1;
		} TrackSensor_bits;
	unsigned int TrackSensor_value;
	} TrackSensor_status;
#define Middle HAL_GPIO_ReadPin(P_MID_GPIO_Port, P_MID_Pin)
#define Left1 HAL_GPIO_ReadPin(P_L1_GPIO_Port, P_L1_Pin)
#define Left2 HAL_GPIO_ReadPin(P_L2_GPIO_Port, P_L2_Pin)
#define Left3 HAL_GPIO_ReadPin(P_L3_GPIO_Port, P_L3_Pin)
#define Left4 HAL_GPIO_ReadPin(P_L4_GPIO_Port, P_L4_Pin)
#define Right1 HAL_GPIO_ReadPin(P_R1_GPIO_Port, P_R1_Pin)
#define Right2 HAL_GPIO_ReadPin(P_R2_GPIO_Port, P_R2_Pin)
#define Right3 HAL_GPIO_ReadPin(P_R3_GPIO_Port, P_R3_Pin)
#define Right4 HAL_GPIO_ReadPin(P_R4_GPIO_Port, P_R4_Pin)
volatile uint32_t getTrackStatus();
void FollowLine(void);
#endif
/* BSP_Track_H_ */
