#include "hc_sr04.h"
#include "gpio.h"
Hc_Sr04 hc_sr04[7];

/**
  * @brief  ������������Trig��������500us
  * @param  ��
  * @retval ��
  */
void HC_SR04_Trig(void)
{
	
	{
		HAL_GPIO_WritePin(Trig_U_GPIO_Port,Trig_U_Pin,GPIO_PIN_SET);
		HcSr04_Delay(500);
		HAL_GPIO_WritePin(Trig_U_GPIO_Port,Trig_U_Pin,GPIO_PIN_RESET);
	}
	{
		HAL_GPIO_WritePin(Trig_LU_GPIO_Port,Trig_LU_Pin,GPIO_PIN_SET);
		HcSr04_Delay(500);
		HAL_GPIO_WritePin(Trig_LU_GPIO_Port,Trig_LU_Pin,GPIO_PIN_RESET);
	}
	{
		HAL_GPIO_WritePin(Trig_RU_GPIO_Port,Trig_RU_Pin,GPIO_PIN_SET);
		HcSr04_Delay(500);
		HAL_GPIO_WritePin(Trig_RU_GPIO_Port,Trig_RU_Pin,GPIO_PIN_RESET);
	}
	{
		HAL_GPIO_WritePin(Trig_LD_GPIO_Port,Trig_LD_Pin,GPIO_PIN_SET);
		HcSr04_Delay(500);
		HAL_GPIO_WritePin(Trig_LD_GPIO_Port,Trig_LD_Pin,GPIO_PIN_RESET);
	}
	{
		HAL_GPIO_WritePin(Trig_RD_GPIO_Port,Trig_RD_Pin,GPIO_PIN_SET);
		HcSr04_Delay(500);
		HAL_GPIO_WritePin(Trig_RD_GPIO_Port,Trig_RD_Pin,GPIO_PIN_RESET);
	}

	
}
/**
  * @brief  HAL�����벶��ص�����
  * @param  htim TIM����ṹ��ָ��
  * @retval ��
  */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	
	if(htim == &(htim9))
	{
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			HcSr04_CaptureCallBack(&hc_sr04[2]);
		}
		else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
		{
			HcSr04_CaptureCallBack(&hc_sr04[3]);
		}
	}
	else if(htim == &(htim10))
	{
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			HcSr04_CaptureCallBack(&hc_sr04[0]);
		}
	}

		else if(htim == &(htim12))
	{
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			HcSr04_CaptureCallBack(&hc_sr04[4]);
		}
		else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
		{
			HcSr04_CaptureCallBack(&hc_sr04[5]);
		}
	}
	
	
}
/**
  * @brief  HcSr04�Ĳ���ص�����
  * @param  htim TIM����ṹ��ָ��
  * @retval ��
  */
void HcSr04_CaptureCallBack(Hc_Sr04 * hcsr)
{
	TIM_HandleTypeDef * timHandle;
	uint32_t tim_channel;
	switch(hcsr->Hcsr04_ID)
	{
		case 1:
		{
			timHandle = &htim10;
			tim_channel = TIM_CHANNEL_1;
			break;
		}
		case 3:
		{
			timHandle = &htim9;
			tim_channel = TIM_CHANNEL_1;
			break;
		}
		case 4:
		{
			timHandle = &htim9;
			tim_channel = TIM_CHANNEL_2;
			break;
		}
		case 5:
		{
			timHandle = &htim12;
			tim_channel = TIM_CHANNEL_1;
			break;
		}
		case 6:
		{
			timHandle = &htim12;
			tim_channel = TIM_CHANNEL_2;
			break;
		}

	}

	if(!(hcsr->Capture_STA & 0x80))//δ��ɲ���
	{
		
		if(hcsr->Capture_STA & 0x40)//���񵽵͵�ƽ
		{
			
		hcsr->Capture_STA=0;//�������
		if(HAL_TIM_ReadCapturedValue(timHandle,tim_channel) < hcsr->cntStart) 
			{
				hcsr->cntCounter = 7999 + HAL_TIM_ReadCapturedValue(timHandle,tim_channel) - hcsr->cntStart;
			}
			else hcsr->cntCounter = HAL_TIM_ReadCapturedValue(timHandle,tim_channel) - hcsr->cntStart;
			
	    {
	    if(hcsr->filterpoint==10)
			{
			hcsr->filterpoint=0;
			}
			hcsr->cntArray[hcsr->filterpoint++] = hcsr->cntCounter * HCSR04_Changemm;
						hcsr->distance = Hcsr04_Fliter(hcsr);
			}		
			TIM_RESET_CAPTUREPOLARITY(timHandle,tim_channel);
			TIM_SET_CAPTUREPOLARITY(timHandle,tim_channel,TIM_ICPOLARITY_RISING);
    }
  
	//���񵽸ߵ�ƽ
		else
		{
			hcsr->Capture_STA |= 0x40;
			hcsr->cntStart = HAL_TIM_ReadCapturedValue(timHandle,tim_channel);
			TIM_RESET_CAPTUREPOLARITY(timHandle,tim_channel); 
			TIM_SET_CAPTUREPOLARITY(timHandle,tim_channel,TIM_ICPOLARITY_FALLING);
		}
	}
}
/**
  * @brief  �������ṹ���ʼ��
  * @param  hcsr �������ṹ��ָ��
  * @retval ��
  */
void HcSr04_Init(Hc_Sr04 * hc_sr)
{
	for(uint8_t i=0; i<6; i++){
		
		hc_sr[i].Hcsr04_ID = i+1;
		hc_sr[i].cntStart = 0;
		hc_sr[i].cntCounter = 0;
		hc_sr[i].Capture_STA = 0;
		hc_sr[i].filterpoint = 0;
		for(uint8_t j=0; j<10; j++)
		{
			hc_sr[i].cntArray[j] = 0;
		}
	}
	//�������벶���ж�
	HAL_TIM_IC_Start_IT(&htim9,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim9,TIM_CHANNEL_2);
	HAL_TIM_IC_Start_IT(&htim10,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim12,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim12,TIM_CHANNEL_2);
}
/**
  * @brief  HCSR04�˲�+�㷨
  * @param  hcsr �������ṹ��ָ��
  * @retval �˲����ֵ
  */
uint16_t Hcsr04_Fliter(Hc_Sr04 * hcsr)
{
	uint16_t temp;
	//���������٣���ð������On(n2)û����
	for(uint8_t i=0; i<10; i++)
	{
		for(uint8_t j=i+1; j<10; j++)
		{
			if(hcsr->cntArray[i] > hcsr->cntArray[j])
			{
				temp  = hcsr->cntArray[j];
				hcsr->cntArray[j] = hcsr->cntArray[i];
				hcsr->cntArray[i] = temp;
			}
		}
	}
	
	//ȡ�м�4��ֵ��ֵ
	return (uint16_t) ((hcsr->cntArray[3]+hcsr->cntArray[4]+hcsr->cntArray[5]+hcsr->cntArray[6])/4);
}
/**
  * @brief  ��������ʱ����
  * @param  i ��ʱʱ��
  * @retval ��
  */
void HcSr04_Delay(__IO uint32_t i){
	
	while(i--);
}
