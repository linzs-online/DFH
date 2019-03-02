#ifndef __PATH_PLANNING_H
#define __PATH_PLANNING_H
#include "stm32f4xx_hal.h"


#define Yaw_Error_Value (1.0f) //�Ƕ��ݲ�
#define HCSR_Error_Value (5.0f) //�����ݲ�mm
#define Speed_Error_Value (0)//�ٶ��ݲ�
#define HCSR_Distance_Point (120)//Ŀ�����mm

#define AF_Distance_Point (225)//Ԥɲ������mm
#define Angel_Point (32)//Ŀ��Ƕ�


#define PWM_max 8000

typedef volatile struct __Path_Plan
{
	uint8_t FlagGet;
	uint8_t FlagFinish;
}Path_Plan;

extern int pwm1,pwm2,pwm3,pwm4;
extern float lineYaw;
extern uint8_t endflag;


/*-------------------------------------- ·���滮��غ��� --------------------------------------*/
void Path_Init(void);
void Path_All_Deal(void);
/*-------------------------------------- ��ص�PID���㼰�ײ���ƺ��� --------------------------------------*/

void Rotate_Left(void);
void Rotate_Right(void);
void Motor_Stop(void);
void Go_Stright_line(void);
void Mecanum_Drive(int x, int y, int z);
void SpeedPID_Calc(void);
void Go_Stright_Low_line(void);
	
/*-------------------------------------- �������ú��� --------------------------------------*/
void YawPID_Calc(void);
void HCSRPID_Calc(void);
void PidDebugFunc(void);
void Debug_Picking(void);
/*-------------------------------------- ·���滮���� --------------------------------------*/
void Path_All_Deal(void);
uint8_t Path_Zero_Deal(void);
uint8_t Path_One_Deal(void);
uint8_t Path_Two_Deal(void);
uint8_t Path_Three_Deal(void);
uint8_t Path_Four_Deal(void);
uint8_t Path_Five_Deal(void);
uint8_t Path_Six_Deal(void);
uint8_t Path_Seven_Deal(void);
uint8_t Path_Eight_Deal(void);
uint8_t Path_Nine_Deal(void);
uint8_t Path_Ten_Deal(void);
uint8_t Path_Eleven_Deal(void);
uint8_t Path_Twelve_Deal(void);
void Path_Plan_Finish(void);
void PathPlanStruct_Init(void);
#endif
