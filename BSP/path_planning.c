#include "path_planning.h"
#include "GY953.h"
#include "pid.h"
#include "hc_sr04.h"
#include "encoder.h"
#include "motor.h"
#include "led.h"
#include "OpenMV_RX.h"

uint8_t endflag = 0;
uint16_t lineSpeed=50;

uint16_t LINE_High_SPEED=70;
uint16_t LINE_Middle_SPEED=50 ;//45
uint16_t LINE_Low_SPEED=29;//25

uint16_t ROTATE_LOW_SPEED=30;
extern int MySecond1,MySecond2;
int YAW_Angle_Point=0; //YAW��Ŀ��Ƕ�
int pwm1,pwm2,pwm3,pwm4;

Path_Plan pathFlag[15];
int finish_flag=0;
extern angle Angle; 
extern Encoder encoder;
extern Hc_Sr04 hc_sr04[7];

extern PIDStruct Motor1_SpeedPID;
extern PIDStruct Motor2_SpeedPID;  
extern PIDStruct Motor3_SpeedPID;
extern PIDStruct Motor4_SpeedPID;

extern PIDStruct Yaw_PID;
extern PIDStruct HCSR_PID;


/*-------------------------------------- ·���滮���ֺ��� --------------------------------------*/
 void Path_Init(void)
{
	for(int i=0; i<=15; i++)
	{
		pathFlag[i].FlagGet = 0;
		pathFlag[i].FlagFinish = 0;
	}
}

void Path_All_Deal(void)
{

}


/*-------------------------------------- ���Ʋ��� --------------------------------------*/
/**
  * @brief  ��ת����
  * @param  ��
  * @retval ��
  */
void Rotate_Left(void)
{
	Motor1_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;
	Motor2_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
	Motor3_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;  
	Motor4_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
}
/**
  * @brief  ��ת����
  * @param  ��
  * @retval ��
  */
void Rotate_Right(void)
{
	Motor1_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
	Motor2_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;
	Motor3_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
	Motor4_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;
}

/**
  * @brief  �����������
  * @param  ��
  * @retval ��
  */
void Motor_Stop(void)
{
	Motor1_SpeedPID.SetPoint = 0;
	Motor2_SpeedPID.SetPoint = 0;
	Motor3_SpeedPID.SetPoint = 0;
	Motor4_SpeedPID.SetPoint = 0;
}

/**
  * @brief  С��ֱ��PID����
  * @param  lineSpeed ֱ���ٶ�
  * @retval ��
  */
void Go_Stright_Low_line(void)
{
	LED_Off;
	//λ�û��ջ�	
	Position_HCSR_PID_Calc(&HCSR_PID,HCSR_Distance_Point,HCSR_LU,HCSR_Error_Value,50);
	//YAW���⻷PID�ջ�
	Position_YAW_PID_Calc(&Yaw_PID,YAW_Angle_Point,Angle.car,Yaw_Error_Value,20);
	Mecanum_Drive(HCSR_PID.PWMSum , lineSpeed , Yaw_PID.PWMSum);						
  	
}

/**
  * @brief  ֱ��PID����
  * @param  lineSpeed ֱ���ٶ�
  * @retval ��
  */
void Go_Stright_line(void)
{

}

/**
  * @brief  Mecanum�����ٶȺϳ�
  * @param  x ƽ�����ٶ�
	* @param  y ֱ�����ٶ�
	* @param  z ��ת���ٶ�
  * @retval ��
  */
void Mecanum_Drive(int x, int y, int z)
{

}

/**
  * @brief  �ٶȱջ�PID(�ڻ�)
  * @param  ��
  * @retval ��
  */
void SpeedPID_Calc(void)
{

}


/*-------------------------------------- �������ú��� --------------------------------------*/
/**
  * @brief  HCSRλ�û�PID���㣨���ԣ���ֱ�ߡ�
  * @param  ��
  * @retval ��
  */
void HCSRPID_Calc(void)
{

}

/**
  * @brief  YAW��PID���㣨���ԣ���ֱ�ߡ�
  * @param  ��
  * @retval ��
  */
void YawPID_Calc(void)
{

}

/**
  * @brief  PID���Ժ��������ݲ�����
  * @param  ��
  * @retval ��
  */
void PidDebugFunc(void)
{

}


/*-------------------------------------- debug --------------------------------------*/

void Debug_Picking(void)
{		

}
