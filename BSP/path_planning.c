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
int YAW_Angle_Point=0; //YAW轴目标角度
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


/*-------------------------------------- 路径规划部分函数 --------------------------------------*/
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


/*-------------------------------------- 控制部分 --------------------------------------*/
/**
  * @brief  左转函数
  * @param  无
  * @retval 无
  */
void Rotate_Left(void)
{
	Motor1_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;
	Motor2_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
	Motor3_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;  
	Motor4_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
}
/**
  * @brief  右转函数
  * @param  无
  * @retval 无
  */
void Rotate_Right(void)
{
	Motor1_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
	Motor2_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;
	Motor3_SpeedPID.SetPoint = ROTATE_LOW_SPEED;
	Motor4_SpeedPID.SetPoint = -ROTATE_LOW_SPEED;
}

/**
  * @brief  电机锁死函数
  * @param  无
  * @retval 无
  */
void Motor_Stop(void)
{
	Motor1_SpeedPID.SetPoint = 0;
	Motor2_SpeedPID.SetPoint = 0;
	Motor3_SpeedPID.SetPoint = 0;
	Motor4_SpeedPID.SetPoint = 0;
}

/**
  * @brief  小段直线PID计算
  * @param  lineSpeed 直线速度
  * @retval 无
  */
void Go_Stright_Low_line(void)
{
	LED_Off;
	//位置环闭环	
	Position_HCSR_PID_Calc(&HCSR_PID,HCSR_Distance_Point,HCSR_LU,HCSR_Error_Value,50);
	//YAW轴外环PID闭环
	Position_YAW_PID_Calc(&Yaw_PID,YAW_Angle_Point,Angle.car,Yaw_Error_Value,20);
	Mecanum_Drive(HCSR_PID.PWMSum , lineSpeed , Yaw_PID.PWMSum);						
  	
}

/**
  * @brief  直线PID计算
  * @param  lineSpeed 直线速度
  * @retval 无
  */
void Go_Stright_line(void)
{

}

/**
  * @brief  Mecanum各轴速度合成
  * @param  x 平移轴速度
	* @param  y 直行轴速度
	* @param  z 旋转轴速度
  * @retval 无
  */
void Mecanum_Drive(int x, int y, int z)
{

}

/**
  * @brief  速度闭环PID(内环)
  * @param  无
  * @retval 无
  */
void SpeedPID_Calc(void)
{

}


/*-------------------------------------- 调试所用函数 --------------------------------------*/
/**
  * @brief  HCSR位置环PID计算（调试）【直线】
  * @param  无
  * @retval 无
  */
void HCSRPID_Calc(void)
{

}

/**
  * @brief  YAW轴PID计算（调试）【直线】
  * @param  无
  * @retval 无
  */
void YawPID_Calc(void)
{

}

/**
  * @brief  PID调试函数（内容不定）
  * @param  无
  * @retval 无
  */
void PidDebugFunc(void)
{

}


/*-------------------------------------- debug --------------------------------------*/

void Debug_Picking(void)
{		

}
