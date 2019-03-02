#include "pid.h"

//�ٶȱջ�PID�ṹ��
PIDStruct Motor1_SpeedPID;
PIDStruct Motor2_SpeedPID;
PIDStruct Motor3_SpeedPID;
PIDStruct Motor4_SpeedPID;

//ֱ�߱ջ��ṹ��
PIDStruct Yaw_PID;
//������λ�ñջ��ṹ��
PIDStruct HCSR_PID;


/**
  * @brief  ����ʽPID���㺯��
  * @param  pidStuc pid�ṹ��ָ��
  * @param  currentPoint �������ɼ�ֵ
  * @param  limieValue ����޷�
  * @param  acceptError ���
  * @retval ��
  */
void Inc_PID_Calc(PIDStruct * pidStuc,int SetPoint,float currentPoint,float acceptError, int limitValue)
{
	float nowError,outPut;
	pidStuc->SetPoint = SetPoint;
	nowError = pidStuc->SetPoint - currentPoint;	
	//��������
	if(-acceptError <= nowError  && nowError <= acceptError)
	{
		outPut = 0;	
	}
	else 
	{
		outPut = (pidStuc->Proportion * (nowError - pidStuc->LastError))+ \
					   (pidStuc->Integral * nowError)+ \
	           (pidStuc->Derivative * (nowError - 2*pidStuc->LastError + pidStuc->PrevError));
		pidStuc->PrevError = pidStuc->LastError;
		pidStuc->LastError = nowError;
	}
	pidStuc->PWMSum +=(int)outPut;
	
	//����޷�
	if(pidStuc->PWMSum >= limitValue)
	{
		pidStuc->PWMSum = limitValue;
	}else if (pidStuc->PWMSum <=   (-limitValue))
	{
		pidStuc->PWMSum = -limitValue;
	}
}

/**
  * @brief  ����ٶ�λ��ʽPID���㺯��
  * @param  pidStuc pid�ṹ��ָ��
  * @param  currentPoint �������ɼ�ֵ
  * @param  limieValue ����޷�
  * @param  acceptError ���
  * @retval ��
  */
void Position_Motor_PID_Calc(PIDStruct * pidStuc,int SetPoint,float currentPoint,float acceptError, int limitValue)
{
	static float Bias,Last_bias,Integral_bias,outPut;
	pidStuc->SetPoint = SetPoint;
	Bias = pidStuc->SetPoint - currentPoint;//��ƫ��
  Integral_bias += Bias;	//��ƫ�����
	//��������
	if(-acceptError <= Bias  && Bias <= acceptError)
	{
		outPut = 0;	
	}
	else 
	{
		outPut = (pidStuc->Proportion * Bias)+ \
					   (pidStuc->Integral * Integral_bias)+ \
	           (pidStuc->Derivative * (Bias - Last_bias));
		Last_bias = Bias;
	}
	pidStuc->PWMSum =(int)outPut;
	
	//����޷�
	if(pidStuc->PWMSum >= limitValue)
	{
		pidStuc->PWMSum = limitValue;
	}else if (pidStuc->PWMSum <=   (-limitValue))
	{
		pidStuc->PWMSum = -limitValue;
	}
}

/**
  * @brief  YAW��λ��ʽPID���㺯��
  * @param  pidStuc pid�ṹ��ָ��
  * @param  currentPoint �������ɼ�ֵ
  * @param  limieValue ����޷�
  * @param  acceptError ���
  * @retval ��
  */
void Position_YAW_PID_Calc(PIDStruct * pidStuc,int SetPoint,float currentPoint,float acceptError, int limitValue)
{
	static float Bias,Last_bias,Integral_bias,outPut;
	pidStuc->SetPoint = SetPoint;
	Bias = pidStuc->SetPoint - currentPoint;//��ƫ��
  Integral_bias += Bias;	//��ƫ�����
	//��������
	if(-acceptError <= Bias  && Bias <= acceptError)
	{
		outPut = 0;	
	}
	else 
	{
		outPut = (pidStuc->Proportion * Bias)+ \
					   (pidStuc->Integral * Integral_bias)+ \
	           (pidStuc->Derivative * (Bias - Last_bias));
		Last_bias = Bias;
	}
	pidStuc->PWMSum =(int)outPut;
	
	//����޷�
	if(pidStuc->PWMSum >= limitValue)
	{
		pidStuc->PWMSum = limitValue;
	}else if (pidStuc->PWMSum <=   (-limitValue))
	{
		pidStuc->PWMSum = -limitValue;
	}
}

/**
  * @brief  HCSR��λ��ʽPID���㺯��
  * @param  pidStuc pid�ṹ��ָ��  
  * @param  currentPoint �������ɼ�ֵ
  * @param  limieValue ����޷�
  * @param  acceptError ���
  * @retval ��
  */
void Position_HCSR_PID_Calc(PIDStruct * pidStuc,int SetPoint,float currentPoint,float acceptError, int limitValue)
{
	static float Bias,Last_bias,Integral_bias,outPut;
	pidStuc->SetPoint = SetPoint;
	Bias = pidStuc->SetPoint - currentPoint;//��ƫ��
  Integral_bias += Bias;	//��ƫ�����
	//��������
	if(-acceptError <= Bias  && Bias <= acceptError)
	{
		outPut = 0;	
	}
	else 
	{
		outPut = (pidStuc->Proportion * Bias)+ \
					   (pidStuc->Integral * Integral_bias)+ \
	           (pidStuc->Derivative * (Bias - Last_bias));
		Last_bias = Bias;
	}
	pidStuc->PWMSum =(int)outPut;
	
	//����޷�
	if(pidStuc->PWMSum >= limitValue)
	{
		pidStuc->PWMSum = limitValue;
	}else if (pidStuc->PWMSum <=   (-limitValue))
	{
		pidStuc->PWMSum = -limitValue;
	}
}
/**
  * @brief  PID�ṹ���ʼ������
  * @param  pidStuc PID�ṹ��ָ��
  * @param  SetPoint Ŀ��ֵ
  * @retval ��
  */
void PID_Init(PIDStruct * pidStuc, float kp, float ki, float kd)
{
	pidStuc->PWMSum = 0;
	pidStuc->Proportion = kp;
	pidStuc->Integral = ki;
	pidStuc->Derivative = kd;
	pidStuc->LastError = 0;
	pidStuc->PrevError = 0;
}


/**
  * @brief  PID�趨Ŀ��ֵ
  * @param  pidStuc PID�ṹ��ָ��
  * @param  setPoint Ŀ��ֵ
  * @retval ��
  */

void PID_SetPoint(PIDStruct * pidStuc, int SetPoint)
{
	pidStuc->SetPoint = SetPoint;
}
