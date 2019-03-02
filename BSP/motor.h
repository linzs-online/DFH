#ifndef __MOTOR_H
#define __MOTOR_H
#include "stm32f4xx_hal.h"

#define PWM_LU1 TIM1->CCR1		//��ǰ���PWMͨ��2
#define PWM_LU2 TIM1->CCR2   //��ǰ���PWMͨ��1

#define PWM_RU2 TIM1->CCR3		//��ǰ���PWMͨ��1
#define PWM_RU1 TIM1->CCR4		//��ǰ���PWMͨ��2

#define PWM_LD1 TIM8->CCR1		//�����PWMͨ��1
#define PWM_LD2 TIM8->CCR2		//�����PWMͨ��2

#define PWM_RD2 TIM8->CCR3		//�Һ���PWMͨ��1
#define PWM_RD1 TIM8->CCR4		//�Һ���PWMͨ��2


void Motor_Init(void);
void Set_Pwm(int motor_a,int motor_b,int motor_c,int motor_d);

#endif 
