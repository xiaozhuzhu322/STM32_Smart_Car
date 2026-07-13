#include <stdio.h>
#include <math.h>

#define NUM_SENSORS 9            // 巡线传感器总数量（9个）
#define MIN_SPEED_DIF -300       // 差速下限（负值表示左轮减右轮加）
#define MAX_SPEED_DIF 300        // 差速上限（正值表示左轮加右轮减）

float Kp = 8;                 // 比例系数（核心参数，决定转弯力度）
float Ki = 0.0;                  // 积分系数（用于消除静态误差，当前关闭）
float Kd = 1;                  // 微分系数（用于抑制震荡，使转弯平滑）

float previous_error = 0;        // 上一次的误差（用于计算微分项）
float integral = 0;              // 误差积分累积值（用于计算积分项）

/**
 * @brief  PID 控制器更新函数
 * @param  error 当前误差值（偏差位置）
 * @retval PID输出值（即 speed_dif，范围被限制在 ±300 之间）
 */
int PID_Update(float error)
{
    int PID_Out;

    // 1. 比例项（P）：误差 × 比例系数，当前主要控制力量
    float proportional = Kp * error;

    // 2. 积分项（I）：对误差进行累积积分
    integral += error;
    float integral = Ki * integral;   // 积分值 × 积分系数（Ki=0时该项为0）

    // 3. 微分项（D）：误差变化率 × 微分系数，预测误差趋势
    float derivative = Kd * (error - previous_error);

    // 4. 更新上次误差，供下一周期微分计算使用
    previous_error = error;

    // 5. PID 输出 = P + I + D（四舍五入取整）
    PID_Out = round(proportional + integral + derivative);

    // 6. 输出限幅（防止差速过大导致电机失控）
    if (PID_Out < MIN_SPEED_DIF) {
        PID_Out = MIN_SPEED_DIF;
    }
    if (PID_Out > MAX_SPEED_DIF) {
        PID_Out = MAX_SPEED_DIF;
    }

    return PID_Out;
}

/**
 * @brief  计算偏差值（根据传感器状态计算小车相对赛道的位置）
 * @param  sensor_readings 9位传感器状态值（bit0~8对应9个传感器）
 * @retval 误差值（负值=偏左，正值=偏右，绝对值越大偏离越远）
 */
float Calculate_Error(int sensor_readings)
{
    // 9个传感器的权重（从左到右，从-16到+16，中间为0）
    int weights[NUM_SENSORS] = {-16, -9, -4, -1, 0, 1, 4, 9, 16};

    float error = 0;   // 累计加权误差
    int num = 0;       // 检测到黑线的传感器数量

    // 处理左侧4个传感器（bit0~3），位置权重为负
    for (int i = 1; i <= (NUM_SENSORS - 1) / 2; i++)
    {
        error -= (sensor_readings & 1) * i * i;   // 减去位置权重的平方
        if (sensor_readings & 1 == 1)
        {
            num++;
        }
        sensor_readings = sensor_readings >> 1;   // 右移一位，处理下一个传感器
    }

    // 处理右侧4个传感器（bit4~7），位置权重为正
    for (int i = 1; i <= (NUM_SENSORS - 1) / 2; i++)
    {
        error += (sensor_readings & 1) * i * i;   // 加上位置权重的平方
        if (sensor_readings & 1 == 1)
        {
            num++;
        }
        sensor_readings = sensor_readings >> 1;
    }

    // 处理中间传感器（bit8），只计数，不计入误差（中间位置权重为0）
    if (sensor_readings & 1 == 1)
    {
        num++;
    }

    // 计算平均偏差（多个传感器同时触发时取平均，避免跳变）
    error = error / num;

    return error;
}

/**
 * @brief  PID控制入口函数（供主循环调用）
 * @param  sensor_readings 9位传感器状态值
 * @retval 差速控制值（直接用于左右轮速度调节）
 */
int PID_Control(int sensor_readings)
{
    // 1. 根据传感器状态计算当前偏差
    float error = Calculate_Error(sensor_readings);

    // 2. 调用PID更新函数，得到差速输出
    int pid_output = PID_Update(error);

    return pid_output;
}


