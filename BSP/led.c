#include "led.h"

/**
  * @brief  LED��˸һ��
  * @param  led��˸���ʱ��
  * @retval ��
  */
void LED_Flashing(int delay_ms)
{
 LED_On;
 HAL_Delay(delay_ms);
 LED_Off;
 HAL_Delay(delay_ms);
}

/**
  * @brief  LED������˸
  * @param  led��˸����
  * @retval ��
  */
void LED_Fast_Flashing(int n)
{
	for(uint16_t i=1;i<=n;i++)
	{
		LED_On;
		HAL_Delay(100);
		LED_Off;
		HAL_Delay(100);
	}
}

/**
  * @brief  LED����˸
  * @param  led��˸����
  * @retval ��
  */
void LED_Slow_Flashing(int n)
{
	for(uint16_t i=1;i<=n;i++)
	{
		LED_On;
		HAL_Delay(500);
		LED_Off;
		HAL_Delay(500);
	}
}



