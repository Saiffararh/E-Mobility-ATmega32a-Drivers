/*
 * ADC.h
 *
 *  Created on: ???/???/????
 *      Author: Saif
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include "STD_TYPES.h"

#define CLR_VREF		 0x3F
#define AVCC             0
#define AREF             1
#define _2V              2

#define R_ADJUSTMENT     0
#define L_ADJUSTMENT     1

#define CLR_ADPS		0xF8
#define PRESCALAR_0     0b0000
#define PRESCALAR_2		0b0001
#define PRESCALAR_4		0b0010	
#define PRESCALAR_8		0b0011
#define PRESCALAR_16	0b0100
#define PRESCALAR_32	0b0101
#define PRESCALAR_64	0b0110	
#define PRESCALAR_128	0b0111



#define CLR_CHANNEL		 0xE0
typedef enum
{
ADC_CHANNEL_0,
ADC_CHANNEL_1,
ADC_CHANNEL_2,
ADC_CHANNEL_3,
ADC_CHANNEL_4,
ADC_CHANNEL_5,
ADC_CHANNEL_6,
ADC_CHANNEL_7
}Channel;

typedef enum 
{
OK,
NOK
} ErrorStatus ;

typedef enum 
{
Idle,
Busy 
}ADC_State ;
	
void ADC_INIT(void);
ErrorStatus ADC_SynStartConv(Channel CH, u8 *result);
ErrorStatus ADC_AsynStartConv(Channel CH, u8 *result, void (*func)(void));

#endif /* MCAL_ADC_ADC_H_ */
