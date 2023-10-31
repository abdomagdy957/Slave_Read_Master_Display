
#ifndef TIMERS_H_
#define TIMERS_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

typedef enum{
	TIMER0_STOP=0,		//0:0000
	TIMER0_SCALER_1,	//1:0001
	TIMER0_SCALER_8,	//2:0010
	TIMER0_SCALER_64,	//3:0011
	TIMER0_SCALER_256,	//4:0100
	TIMER0_SCALER_1024,	//5:0101
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_type;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;


typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_CLEAR_ON_COMPARE,
	OC0_SET_ON_COMPARE

}OC0Mode_type;

void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler);

void TIMER0_OC0Mode(OC0Mode_type mode);
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
void TIMER0_OV_SetCallBack(void(*local_fptr)(void));
void TIMER0_OC_SetCallBack(void(*local_fptr)(void));
void TIMER0_SetCompareValue(u8 compare);
void TIMER0_SetTimerValue(u8 counter);
u8	 TIMER0_GetTimerValue(void);

/*********************************************************************************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_CLEAR_ON_COMPARE,
	OCRA_SET_ON_COMPARE

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_CLEAR_ON_COMPARE,
	OCRB_SET_ON_COMPARE

}OC1B_Mode_type;


typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;




void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler);
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode);
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode);
void TIMER1_SetCompareValueA(u16 compare);
void TIMER1_SetCompareValueB(u16 compare);
void TIMER1_SetTimerValue(u16 counter);
u8 TIMER1_GetTimerValue(void);
void TIMER1_SetICUValue(u16 counter);
u16 TIMER1_GetICUValue(void);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);

void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);

void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);

void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));

/*********************************************************************************************************/

typedef enum{
	TIMER2_STOP=0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_64,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024,
	EXTERNAL2_FALLING,
	EXTERNAL2_RISING
}Timer2Scaler_type;

typedef enum
{
	TIMER2_NORMAL_MODE=0,
	TIMER2_PHASECORRECT_MODE,
	TIMER2_CTC_MODE,
	TIMER2_FASTPWM_MODE

}Timer2Mode_type;


typedef enum
{
	OC2_DISCONNECTED=0,
	OC2_TOGGLE,
	OC2_CLEAR_ON_COMPARE,
	OC2_SET_ON_COMPARE

}OC2Mode_type;

void TIMER2_Init(Timer2Mode_type mode,Timer2Scaler_type scaler);

void TIMER2_OC2Mode(OC2Mode_type mode);
void TIMER2_SetCompareValue(u8 compare);
void TIMER2_SetTimerValue(u8 counter);
u8 TIMER2_GetTimerValue(void);

void TIMER2_OV_InterruptEnable(void);
void TIMER2_OV_InterruptDisable(void);
void TIMER2_OC_InterruptEnable(void);
void TIMER2_OC_InterruptDisable(void);
void TIMER2_OV_SetCallBack(void(*local_fptr)(void));
void TIMER2_OC_SetCallBack(void(*local_fptr)(void));

#endif /* TIMERS_H_ */