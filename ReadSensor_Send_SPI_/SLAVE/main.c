#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

#include "DIO.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "SPI.h"


#define  F_CPU	8000000
#include <util/delay.h>

#define PULSE	PINC0

void SPI_Func(void);
volatile u16 lm35_Sensor=0;

int main(void)
{
	SPI_SetCallBack(SPI_Func);
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	sei();
	SPI_Init(SLAVE);
	LCD_WriteString_GoTo(0,0,"slave");
	LCD_WriteString_GoTo(1,0,"LM35:");
	
    while(1) 
    {	
		lm35_read();
	}
}

void SPI_Func(void)
{
	 SPI_SendReceive(lm35_Sensor);
}
void lm35_read(void)
{
	lm35_Sensor = ADC_VoltRead(CH_0);
	LCD_Clear_Position(1,6,6);
	LCD_GoTo(1,6);
	lm35_Sensor =  ((lm35_Sensor>1500)? 150 :(lm35_Sensor/10));	/*CUZ range of lm35 from 0 to 150 celesius so if volt is bigger than 1500 we won't change the temp more than 150*/
	LCD_WriteNumber_2(lm35_Sensor);
	/* threshold is 50 if lm35 sensor exceeds it, it will send pulse on int_0 to tell him send signal to send to master the temperature*/
	if(lm35_Sensor>=50)
	{
		DIO_WritePin(PULSE,HIGH);
		_delay_ms(1);
		DIO_WritePin(PULSE,LOW);
	}
	_delay_ms(250);	//to display the temp sensor on lcd enough time
}