#include "Motor_Driver.h"
#include "tim.h"


#define TIM_MOTOR &htim2
#define PWMA_CHANNEL TIM_CHANNEL_1
#define PWMB_CHANNEL TIM_CHANNEL_2

void Set_MotorState(MotorState_t state)
{
    if(state == MOTOR_FORWARD)
    {
        AIN1_HIG();
        AIN2_LOW();
        BIN1_HIG();
        BIN2_LOW();
    }else if(state == MOTOR_BACKWARD)
    {
        AIN1_LOW();
        AIN2_HIG();
        BIN1_LOW();
        BIN2_HIG();

    }else if(state == MOTOR_BRAKE)
    {
        AIN1_LOW();
        AIN2_LOW();
        BIN1_LOW();
        BIN2_LOW();
    }
}
static inline void __Set_PWMADuty(uint8_t dutyA, uint8_t dutyB)

{
    __HAL_TIM_SET_COMPARE(TIM_MOTOR, PWMA_CHANNEL, dutyA);
    __HAL_TIM_SET_COMPARE(TIM_MOTOR, PWMB_CHANNEL, dutyB);
}
void Motor_Speed(int Speed)
{
    if(Speed > 0)
    {
        Set_MotorState(MOTOR_FORWARD);
        __Set_PWMADuty(Speed,Speed);

    }else if(Speed == 0)
    {
        Set_MotorState(MOTOR_BRAKE);
        __Set_PWMADuty(0,0);
    }else if(Speed < 0)
    {
        Set_MotorState(MOTOR_BACKWARD);
        __Set_PWMADuty(-Speed,-Speed);
    }
}




void Motor_Init(void)
{
    MOTOR_ENABLE();
	HAL_TIM_PWM_Start(TIM_MOTOR, PWMA_CHANNEL);
	HAL_TIM_PWM_Start(TIM_MOTOR, PWMB_CHANNEL);

    Motor_Speed(10);
}
