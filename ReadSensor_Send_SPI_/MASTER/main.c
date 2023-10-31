#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

#include "DIO.h"

#include "LCD_Interface.h"


#include "Ex_Interrupt.h"

#include "Timers.h"
#include "Timers_Services.h"


#include "SPI.h"

#define  F_CPU	8000000
#include <util/delay.h>




void SPI_Func(void);
u8 _data;
void Int0_Fun(void);
int main(void)
{
	
	EXI_SetCallBack(EX_INT0,Int0_Fun);
	SPI_SetCallBack(SPI_Func);
	
	DIO_Init();
	LCD_Init();
	EXI_Init();
	EXI_Enable(EX_INT0);
	
	sei();
	SPI_Init(MASTER);
	
	LCD_WriteString_GoTo(0,0,"master");
	LCD_WriteString_GoTo(1,0,"Read:");


	
	Timer1_SetInterruptTime_s(5,SPI_Func);
    while(1) 
    {	
			LCD_Clear_Position(1,6,5);

			LCD_GoTo(1,6);
			LCD_WriteNumber_2(_data);
			_delay_ms(20);
	
	}
}
void Int0_Fun(void)
{
	_data = SPI_SendReceive('S');
}
void SPI_Func(void)
{
	_data = SPI_SendReceive('S');
}
