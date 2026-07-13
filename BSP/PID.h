#ifndef __PID_H
#define __PID_H



int PID_Update( float error);
float Calculate_Error(int sensor_readings);
int PID_Control(int sensor_readings);


#endif

