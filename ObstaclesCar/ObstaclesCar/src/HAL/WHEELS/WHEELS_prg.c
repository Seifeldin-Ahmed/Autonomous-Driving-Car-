#include "WHEELS_cfg.h"
#include "WHEELS_int.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/PWM/PWM_int.h"

void WHEELS_Init(u8 Copy_InitialSpeed)
{
    PWM_Configure(PWM_PWM0, PWM_PRESCALER_1024, PWM_WGM_FAST_PWM0, 255);
    PWM_ConfigurePin(WHEELS_LEFT_SPEED_PIN, PWM_PIN_MODE_NON_INVERTING, Copy_InitialSpeed);
    PWM_ConfigurePin(WHEELS_RIGHT_SPEED_PIN, PWM_PIN_MODE_NON_INVERTING, Copy_InitialSpeed);
    PWM_StartPWM(PWM_PWM0);
}

void WHEELS_Move(WHEELS_ENUM_Directions Copy_Direction)
{
    switch (Copy_Direction)
    {
    case WHEELS_DIRECTION_FORWARD:
        // Move Left Wheels Forward
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_POSITIVE_PIN, DIO_HIGH);
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_NEGATIVE_PIN, DIO_LOW);
        // Move Right Wheels Forward
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_POSITIVE_PIN, DIO_HIGH);
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_NEGATIVE_PIN, DIO_LOW);
        break;

    case WHEELS_DIRECTION_BACKWARD:
        // Move Left Wheels Backward
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_POSITIVE_PIN, DIO_LOW);
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_NEGATIVE_PIN, DIO_HIGH);
        // Move Right Wheels Backward
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_POSITIVE_PIN, DIO_LOW);
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_NEGATIVE_PIN, DIO_HIGH);
        break;

    case WHEELS_DIRECTION_LEFT:
        // Move Left Wheels Backward
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_POSITIVE_PIN, DIO_LOW);
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_NEGATIVE_PIN, DIO_HIGH);
        // Move Right Wheels Forward
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_POSITIVE_PIN, DIO_HIGH);
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_NEGATIVE_PIN, DIO_LOW);
        break;

    case WHEELS_DIRECTION_RIGHT:
        // Move Left Wheels Forward
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_POSITIVE_PIN, DIO_HIGH);
        DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_NEGATIVE_PIN, DIO_LOW);
        // Move Right Wheels Backward
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_POSITIVE_PIN, DIO_LOW);
        DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_NEGATIVE_PIN, DIO_HIGH);
        break;
    }
}

void WHEELS_Stop()
{
    // Stop Left Wheels
    DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_POSITIVE_PIN, DIO_LOW);
    DIO_SetPinValue(WHEELS_LEFT_DIRECTION_PORT, WHEELS_LEFT_NEGATIVE_PIN, DIO_LOW);
    // Stop Right Wheels
    DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_POSITIVE_PIN, DIO_LOW);
    DIO_SetPinValue(WHEELS_RIGHT_DIRECTION_PORT, WHEELS_RIGHT_NEGATIVE_PIN, DIO_LOW);
}

void WHEELS_SetSpeed(u8 Copy_Speed)
{
    // Set Left Wheels Speed
    PWM_ConfigurePin(WHEELS_LEFT_SPEED_PIN, PWM_PIN_MODE_NON_INVERTING, Copy_Speed);
    // Set Right Wheels Speed
    PWM_ConfigurePin(WHEELS_RIGHT_SPEED_PIN, PWM_PIN_MODE_NON_INVERTING, Copy_Speed);
}
