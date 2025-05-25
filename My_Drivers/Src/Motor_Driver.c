#include "Motor_Driver.h"

void Set_MotorState(MotorState_t state)
{
    if(state == MOTOR_FORWARD)
    {
        AIN1_HIG();
        AIN2_LOW();
    }else if(state == MOTOR_BACKWARD)
    {
        AIN1_LOW();
        AIN2_HIG();

    }else if(state == MOTOR_BRAKE)
    {
        AIN1_LOW();
        AIN2_LOW();
    }
}
