#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__
#include "main.h"

#define AIN1_HIG()          HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET)
#define AIN1_LOW()          HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET)
#define AIN2_HIG()          HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET)
#define AIN2_LOW()          HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET)
#define MOTOR_ENABLE()      HAL_GPIO_WritePin(STBY_GPIO_Port, STBY_Pin, GPIO_PIN_SET)
#define MOTOR_DISABLE()     HAL_GPIO_WritePin(STBY_GPIO_Port, STBY_Pin, GPIO_PIN_RESET)

// 电机状态
typedef enum
{
    MOTOR_FORWARD,         // 电机正传
    MOTOR_BACKWARD,        // 电机反转
    MOTOR_BRAKE,           // 电机刹车
}MotorState_t;


void Motor_Init(void);
void Motor_Speed(int Speed);
#endif
