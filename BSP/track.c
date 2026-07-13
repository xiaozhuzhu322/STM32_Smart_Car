#include "stdio.h"
#include "Track.h"



volatile int status = 0;	//寻迹点状态
int speed,speed_dif,dir_LR;				//基本速度、差速、方向
/*
 * 返回0	表示未寻到线
 * */
volatile uint32_t getTrackStatus()
{
	TrackSensor_status status;
	status.TrackSensor_value = 0;

	status.TrackSensor_bits.left1 = Left1;
	status.TrackSensor_bits.left2 = Left2;
	status.TrackSensor_bits.left3 = Left3;
	status.TrackSensor_bits.left4 = Left4;

	status.TrackSensor_bits.right1 = Right1;
	status.TrackSensor_bits.right2 = Right2;
	status.TrackSensor_bits.right3 = Right3;
	status.TrackSensor_bits.right4 = Right4;

	status.TrackSensor_bits.middle = Middle;

	return (status.TrackSensor_value&0x1ff);
}

void FollowLine(void)
{
	uint8_t left_status = 0, right_status = 0, middle_status = 0;
	static uint8_t posture = 0x0;


	status=getTrackStatus();
	left_status = status&0xf;		//低4位代表左侧的点的值
	right_status = (status>>4)&0xf;	//高4位代表右侧的点的的值
	middle_status = status>>8;		//最高的1位为代表中间的点的值

}
