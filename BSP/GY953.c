#include "GY953.h"
#include "usart.h"
#include "led.h"
#include <math.h>



gy953 GY953;
angle Angle; 

uint8_t  data_buf[13]; 
uint8_t sent_buf1[3]={0xa5,0xaf,0x54}; // 波特率设置为115200
uint8_t sent_buf2[3]={0xa5,0xa4,0x49}; // 数据输出速率50hz
uint8_t sent_buf3[3]={0xa5,0x45,0xEA}; // 欧拉角（默认50HZ）(自动输出指令)
uint8_t sent_buf4[3]={0xa5,0x57,0xFC}; // 加计陀螺校准
uint8_t sent_buf5[3]={0xa5,0x65,0x0A}; // 四元数
uint8_t sent_buf6[3]={0xa5,0xa6,0x4B}; // 数据输出速率200hz
uint8_t sent_buf7[3]={0xa5,0X59,0xFE}; // 恢复出厂设置
 
/**
  * @brief  陀螺仪初始化函数
  * @param  无
  * @retval 无
  */
void GY953_Init(void)
{

} 

/**
  * @brief  陀螺仪值函获取函数
  * @param  无
  * @retval 陀螺仪数值
  */
int16_t GY953_GetDate(void)
{
 return 0;
}  


/**
  * @brief  方向定位函数
  * @param  无
  * @retval 无
  */
void Angle_Init(void)
{

}

/**
  * @brief  方向定位辅助函数
  * @param  无
  * @retval 无
  */
void Angle_change(void)
{

}
