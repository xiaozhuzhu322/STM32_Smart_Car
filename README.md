# STM32F407 智能避线巡线小车

基于 STM32F407IGH6 + FreeRTOS 的智能小车控制系统，实现循迹、避障、PID 速度控制。

## 功能清单
- 9 路巡线传感器循迹
- 超声波避障（中断方式测距）
- PID 速度闭环控制
- FreeRTOS 多任务调度
- 四路独立 PWM 电机驱动
- 虚拟仿真平台演示

## 技术栈
- 主控：STM32F407IGH6
- 传感器：9路巡线传感器、超声波模块
- 执行器：4路直流电机（PWM调速）
- 操作系统：FreeRTOS
- 开发环境：STM32CubeIDE / Keil

## 项目结构
- Core/BSP/ - 板级支持包（PID控制、巡线传感器）
- Core/Inc/ - 头文件
- Core/Src/ - 源文件（main.c、freertos.c等）
- Core/Startup/ - 启动文件

## 演示视频
[点击观看演示视频](docs/demo.mp4)（待上传）


## 作者
李宜万 | 应急管理大学 物联网工程
GitHub：[xiaozhuzhu322](https://github.com/xiaozhuzhu322)
