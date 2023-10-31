#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "SPI.h"

static void(*SPI_Fptr)(void)=NULLPTR;

void SPI_Init(SPIMode_type mode)
{
	if (mode==MASTER)
	{
		//clock 2MHZ
		SET_BIT(SPCR,MSTR);
	}
	else
	{
		CLEAR_BIT(SPCR,MSTR);
	}
	// SPI ENABLE
	SET_BIT(SPCR,SPE);
	//SPI Interrupt enable
	SET_BIT(SPCR,SPIE);
}

u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}

u8 SPI_ReceivePerodic(u8*pdata)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}
u8 SPI_Receive_NoBlock(void)
{
	return SPDR;
}
void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}
void SPI_SetCallBack(void (*LocalFptr)(void))
{
	SPI_Fptr = LocalFptr;
}
ISR(SPI_STC_vect)
{
	if (SPI_Fptr!=NULLPTR)
	{
		SPI_Fptr();
	}
}