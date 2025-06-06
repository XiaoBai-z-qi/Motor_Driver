#ifndef __MOTOR_DRIVER_H__
#define __MOTOR_DRIVER_H__
#include "main.h"

#define AIN1_HIG()          HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET)
#define AIN1_LOW()          HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET)
#define AIN2_HIG()          HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET)
#define AIN2_LOW()          HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET)
#define BIN1_HIG()          HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_SET)
#define BIN1_LOW()          HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET)
#define BIN2_HIG()          HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_SET)
#define BIN2_LOW()          HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_RESET)
#define MOTOR_ENABLE()      HAL_GPIO_WritePin(STBY_GPIO_Port, STBY_Pin, GPIO_PIN_SET)
#define MOTOR_DISABLE()     HAL_GPIO_WritePin(STBY_GPIO_Port, STBY_Pin, GPIO_PIN_RESET)


#define TIM_MOTOR &htim2
#define TIM_ENCODERA &htim3
#define TIM_ENCODERB &htim4
#define PWMA_CHANNEL TIM_CHANNEL_1
#define PWMB_CHANNEL TIM_CHANNEL_2

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
