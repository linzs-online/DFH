#include "GY953.h"
#include "usart.h"
#include "led.h"
#include <math.h>



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

} 

/**
  * @brief  ������ֵ����ȡ����
  * @param  ��
  * @retval ��������ֵ
  */
int16_t GY953_GetDate(void)
{
 return 0;
}  


/**
  * @brief  ����λ����
  * @param  ��
  * @retval ��
  */
void Angle_Init(void)
{

}

/**
  * @brief  ����λ��������
  * @param  ��
  * @retval ��
  */
void Angle_change(void)
{

}
