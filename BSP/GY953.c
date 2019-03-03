#include "GY953.h"
#include "usart.h"
#include "led.h"
#include <math.h>

/*����GY953�����ǵ����⣬Angle.time������������Angle.car�Լ���
  ��������Yaw��Ŀ��ֵ�Լ��Ե����������*/
	
/*��ͷ�Ұ�Angle.time���٣�Angle.car����
  ��ͷ���Angle.time����Angle.car����*/

gy953 GY953;
angle Angle; 

uint8_t  data_buf[13]; 
uint8_t sent_buf1[3]={0xa5,0xaf,0x54}; // ����������Ϊ115200
uint8_t sent_buf2[3]={0xa5,0xa4,0x49}; // �����������50hz
uint8_t sent_buf3[3]={0xa5,0x45,0xEA}; // ŷ���ǣ�Ĭ��50HZ��(�Զ����ָ��)
uint8_t sent_buf4[3]={0xa5,0x57,0xFC}; // �Ӽ�����У׼
uint8_t sent_buf5[3]={0xa5,0x65,0x0A}; // ��Ԫ��
uint8_t sent_buf6[3]={0xa5,0xa6,0x4B}; // �����������200hz
uint8_t sent_buf7[3]={0xa5,0X59,0xFE}; // �ָ���������
 
/**
  * @brief  �����ǳ�ʼ������
  * @param  ��
  * @retval ��
  */
void GY953_Init(void)
{
	  HAL_UART_Receive_DMA(&huart3,data_buf,13);// ����DMA����
		/*HAL_UART_Transmit_DMA(&huart3,sent_buf7,3);
		HAL_Delay(1000);
	  */
		HAL_UART_Transmit_DMA(&huart3,sent_buf1,3);
		HAL_Delay(1000);
	  HAL_UART_Transmit_DMA(&huart3,sent_buf4,3);
		HAL_Delay(1000);
		HAL_UART_Transmit_DMA(&huart3,sent_buf6,3);
		HAL_Delay(1000);
	  HAL_UART_Transmit_DMA(&huart3,sent_buf5,3);
		HAL_Delay(1000);   
	
    LED_Slow_Flashing(5);
} 

/**
  * @brief  ������ֵ����ȡ����
  * @param  ��
  * @retval ��������ֵ
  */
int16_t GY953_GetDate(void)
{
	int16_t q0=0,q1=0,q2=0,q3=0;
	int16_t YAW=66;
	if(data_buf[2]==0x65)
	{
		q0=((data_buf[4]<<8)|data_buf[5]);
		q1=((data_buf[6]<<8)|data_buf[7]);
		q2=((data_buf[8]<<8)|data_buf[9]);
		q3=((data_buf[10]<<8)|data_buf[11]);
	
		YAW = atan2( 2 * (q0 * q3 +q2 * q1), q0*q0 + q1*q1 - q2*q2 - q3*q3 )*57.3 ;
		return YAW;
	}
	else
	{		
		LED_Flashing(70);
		return 0;
	}
}  


/**
  * @brief  ����λ����
  * @param  ��
  * @retval ��
  */
void Angle_Init(void)
{
	GY953_Init();
	Angle.front=GY953_GetDate();
	Angle.flag=0;
	if(Angle.front>=90)
	{
		Angle.right=Angle.front-90;
		Angle.left=Angle.front-270;
		Angle.back=Angle.front-180;
	}
	else if(Angle.front<90&&Angle.front>=0)
	{
		Angle.right=Angle.front-90;
		Angle.left=Angle.front+90;
		Angle.back=Angle.front-180;
	}
	else if(Angle.front<0&&Angle.front>=-90)
	{
		Angle.right=Angle.front-90;
		Angle.left=Angle.front+90;
		Angle.back=Angle.front+180;
	}
	else if(Angle.front<-90)
	{
		Angle.right=Angle.front+270;
		Angle.left=Angle.front+90;
		Angle.back=Angle.front+180;
	}
}

/**
  * @brief  ����λ��������
  * @param  ��
  * @retval ��
  */
void Angle_change(void)
{
	if(Angle.flag==Go_straight)
	{
		Angle.car=Angle.front-Angle.time;
		if(Angle.car>180)
		{
			Angle.car-=360;
		}
		else if(Angle.car<-180)
		{
			Angle.car+=360;
		}
	}
	else if(Angle.flag==Turn_right_90)
	{
	Angle.car=Angle.right-Angle.time;
		if(Angle.car>180)
		{
			Angle.car-=360;
		}
		else if(Angle.car<-180)
		{
			Angle.car+=360;
		}
	}
		else if(Angle.flag==Turn_left_90)
	{
	Angle.car=Angle.left-Angle.time;
		if(Angle.car>180)
		{
			Angle.car-=360;
		}
		else if(Angle.car<-180)
		{
			Angle.car+=360;
		}
	}
		else if(Angle.flag==Back)
	{
	Angle.car=Angle.back-Angle.time;
		if(Angle.car>180)
		{
			Angle.car-=360;
		}
		else if(Angle.car<-180)
		{
			Angle.car+=360;
		}
	}
}
