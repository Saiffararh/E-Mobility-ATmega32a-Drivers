/*

 * ADC.c
 *
 *  Created on: ???/???/????
 *      Author: Saif
 */
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_CFG.h"
#include "ADC.h"


void ADC_INIT(void)
{
#if ADC_VREF  ==  AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif  ADC_VREF  ==  AREF
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif ADC_VREF  ==  _2V
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#endif

#if ADC_ADJUSTMENT == L_ADJUSTMENT
	SET_BIT(ADMUX,5);
	
#endif

	/*_TO_CHOOSE_AUTO_TRIGGER_MODE_*/
	SET_BIT(ADCSRA,5);
	
	/*_TO_CHOOSE_BETWEEN_ADC_PRESCALAR_*/
	
	ADCSRA &= CLR_ADPS ;
	ADCSRA |= ADC_PRESCALER ;
	
	/*_TO_ENABLE_ADC_*/
	SET_BIT(ADCSRA,7);
	
}


ErrorStatus ADC_SynStartConv(Channel CH ,u8 *result)
{
	ErrorStatus State = OK ;
	
	/*_TO_CHOOSE_ADC_CHANNEL */
	ADMUX &= CLR_CHANNEL ;
	ADMUX |= CH ;
		
	/*_TO_CHOOSE_START_ADC_CONVERSION */
	
	SET_BIT(ADCSRA,6);
	u16 TimeOutCounter=0 ;
	
	while ( GET_BIT(ADCSRA,4)==0 && TimeOutCounter < 1000000 ) 
	{
		TimeOutCounter++;
		if (TimeOutCounter == 1000000 ){
			
			State = NOK ;
		}
	}
	
	if ( State == OK ) {
	*result = ADCH ;
	}
		
	return State ;
}

volatile u16 ADC_Result ;

ErrorStatus ADC_AsynStartConv(Channel CH, u8 *result, void (*func)(void))
{
	
	u8 ErrorStatus = OK ;
	//ADC_END = func ;
	
	
	/*_TO_CHOOSE_ADC_CHANNEL */
	ADMUX &= CLR_CHANNEL ;
	ADMUX |= CH ;
		
	/*_TO_START_ADC_CONVERSION */
	
	SET_BIT(ADCSRA,6);
	SET_BIT(ADCSRA,3);
	
	*result = ADC_Result ;
	
	return ErrorStatus ;
}

void ADC_END() {
	
	/* 
	
	CODE
	
	*/
	
	
}

void __vector_16 (void) __attribute__ ((signal)); \
void __vector_16 (void)
{
	
	ADC_Result = ADCL | ((u16)ADCH<<8); // right adjustment
	ADC_Result = ADCH ;					// left adjustment
	
	SET_BIT(ADCSRA,4);
	
	
	
}
