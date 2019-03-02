#include "encoder.h"
#include "tim.h"
#include "path_planning.h"
#include "stm32f4xx_hal.h"


Encoder encoder;

/**
  * @brief  �����������ʼ��
  * @param  ��
  * @retval ��
  */
void Encoder_Init(void)
{
	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_ALL);

}

/**
  * @brief  ��λʱ���ȡ����������
  * @param  ��
  * @retval ��ʱ������ֵ
  */
int Read_Encoder(int TIMX)
{
   int Encoder_TIM;    
   switch(TIMX)
	 {
	   case 2:  Encoder_TIM= (short)TIM2 -> CNT;   TIM2 -> CNT=0; break;
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;   TIM3 -> CNT=0; break;
		 case 4:  Encoder_TIM= (short)TIM4 -> CNT;   TIM4 -> CNT=0; break;	
		 case 5:  Encoder_TIM= (short)TIM5 -> CNT;   TIM5 -> CNT=0; break;	
		 default:  Encoder_TIM=0;
	 }
		return Encoder_TIM;
}

/**
  * @brief  �ӱ��������µ���ٶ�
  * @param  ��
  * @retval ��
  */
/*
void Encoder_Update(Encoder * enco)
{    
	//����ԭʼ�ٶ�
	enco->encoder_LU = -(float)(Encoder_Get_Speed(Read_Encoder(2)));
	enco->encoder_RU = (float)(Encoder_Get_Speed(Read_Encoder(3)));
	enco->encoder_LD = -(float)(Encoder_Get_Speed(Read_Encoder(4)));
	enco->encoder_RD = (float)(Encoder_Get_Speed(Read_Encoder(5)));
	
}
*/

/**
  * @brief  �ӱ��������µ���ٶ�
  * @param  ��
  * @retval ��
  */
void Encoder_Update(Encoder * enco)
{    
	//����ԭʼ�ٶ�
	enco->encoder_LU = -Read_Encoder(2);
	enco->encoder_RU = Read_Encoder(3);
	enco->encoder_LD = -Read_Encoder(4);
	enco->encoder_RD = Read_Encoder(5);
	
}









