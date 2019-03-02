#include "path_planning.h"
#include "GY953.h"
#include "pid.h"
#include "hc_sr04.h"
#include "encoder.h"
#include "motor.h"
#include "stm32f4xx_hal.h"

extern gy953 GY953;
extern angle Angle; 
extern Encoder encoder;
extern Hc_Sr04 hc_sr04[7];
extern Path_Plan pathFlag[15];
extern uint16_t lineSpeed;
extern int YAW_Angle_Point;

int timeTick = 0;
int MySecond1 = 0;
int MySecond2 = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == (&htim6))
	{
		timeTick++;
		if(timeTick%10 == 0)
		{	

		}
		if(timeTick%50 == 0)
		{

		}
		if(timeTick%1000 == 0)
		{

		}
	}
}  


