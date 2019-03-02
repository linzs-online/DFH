#ifndef __HC_SR04_H
#define __HC_SR04_H
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "main.h"
#define HCSR04_Changemm 0.85

#define HCSR_LU hc_sr04[2].distance
#define HCSR_LD hc_sr04[4].distance

#define HCSR_RU hc_sr04[3].distance
#define HCSR_RD hc_sr04[5].distance

#define HCSR_U hc_sr04[0].distance



typedef volatile struct __Hc_Sr04{

	uint8_t Hcsr04_ID;
	
	uint16_t Capture_STA;//����λΪ������ɱ�־������λΪ�ߵ�ƽ������ɱ�־������λΪ�������
	
	uint16_t cntStart;
	
	uint16_t cntCounter; //CNT����ֵ
	
	uint16_t distance;
	
	uint16_t cntArray[10];//�˲����������
	
	uint8_t  filterpoint;//�˲�ָ��
}Hc_Sr04;

extern Hc_Sr04 hc_sr04[7];

void HC_SR04_Trig(void);

void HcSr04_Init(Hc_Sr04 * hc_sr);

void HcSr04_CaptureCallBack(Hc_Sr04 * hcsr);

uint16_t Hcsr04_Fliter(Hc_Sr04 * hcsr);

void HcSr04_Delay(__IO uint32_t i);

#endif
