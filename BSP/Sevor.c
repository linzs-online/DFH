#include "Sevor.h"
#include "stm32f4xx_hal.h"
#include "tim.h"

/**
  * @brief  �����ʼ��
  * @param  ��
  * @retval ��
  */
void Sevor_Init(void)
{
	HAL_TIM_PWM_Start(&htim11,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim13,TIM_CHANNEL_1);
//HAL_TIM_PWM_Start(&htim14,TIM_CHANNEL_1);
	
  Sevor_1_PWM=100; //�ұ�     ����--->̧��   [100,200]   ��ֱ��100
	Sevor_2_PWM=200; //���     ����--->̧��   [200,100]   ��ֱ��200 
}


void Picking_Go(void)
{
  Sevor_1_PWM=200; 
	Sevor_2_PWM=100;  
}

void Picking_Up(void)
{
  Sevor_1_PWM=100; 
	Sevor_2_PWM=200; 
}

