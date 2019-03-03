#include "OpenMV_RX.h"
#include "Sevor.h"
#include "stm32f4xx_hal.h"
#include "hc_sr04.h"
#include "path_planning.h" 
#include "led.h"

extern uint16_t lineSpeed;

extern uint16_t LINE_High_SPEED;
extern uint16_t LINE_Middle_SPEED;
extern uint16_t LINE_Low_SPEED;
extern int MySecond1,MySecond2;

int OpenMV_control(void)
{	
	if(HCSR_U < 400)
		{
		  Picking_Up();
			//return 0;
		}
  if(HAL_GPIO_ReadPin(GPIOA,OpenMV_RX2_Pin)==1) //����2RX��  
		{
			MySecond1 = 0;                                                                                                                                                                                                             
	 		Sevor_1_PWM=202;                  //�ұ�
			LED_On ;
			lineSpeed=35;
		}

	if(HAL_GPIO_ReadPin(GPIOA,OpenMV_RX1_Pin)==1) //����2TX��
		{		
		 MySecond2 = 0;
		 Sevor_2_PWM=98;                    //���
		 LED_On ;
		 lineSpeed=35;
		 }
  if(MySecond1 == 3 )
		{
			Sevor_1_PWM=100; 
		  LED_Off ;
		  lineSpeed=LINE_Middle_SPEED;
		}
	if(MySecond2 == 3 )
		{
		 Sevor_2_PWM=200;
		 LED_Off ;
		 lineSpeed=LINE_Middle_SPEED;
		}
	return 0;
}

int OpenMV_control_R(void)
{
	if(HCSR_U < 400)
		{
		 Picking_Up();
			//return 0;
		}
  if(HAL_GPIO_ReadPin(GPIOA,OpenMV_RX2_Pin)==1) //����2RX��  
		{ 
		MySecond1 = 0;
		Sevor_1_PWM=202;                  //�ұ�
		LED_On ;
		lineSpeed=35;
		}
	if(MySecond1 == 3 )
	{
		Sevor_1_PWM=100; 
		LED_Off ;
	 lineSpeed=LINE_Middle_SPEED;
	}
	return 0;
}

int OpenMV_control_L(void)
{
	if(HCSR_U < 400)
		{
		 Picking_Up();
			//return 0;
		}
  if(HAL_GPIO_ReadPin(GPIOA,OpenMV_RX1_Pin)==1) //����2TX��
		{		
		 MySecond2 = 0;
		 Sevor_2_PWM=98;                    //���
		 LED_On ;
		 lineSpeed=30;
		 }
	if(MySecond2 == 3 )
		{
		 Sevor_2_PWM=200;
		 LED_Off ;
		 lineSpeed=LINE_Middle_SPEED;
		}
		return 0;
}

