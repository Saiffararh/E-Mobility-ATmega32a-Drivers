/*
 * ADC_CFG.h
 *
 *  
 *      Author: Saif Fararh
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_


#define CHANNEL ADC_CHANNEL_2

/* SELECT_CHANNEL */
/* OPTIONS -> ADC_CHANNEL_0 TO ADC_CHANNEL_7     */
/* CHOOSE FROM [0-7] and WRTIE IT */

/*_SELECT_VREF_*/
/*_OPTIONS -> [ AVCC ] , [ AREF ] , [ _2V ] _*/
#define ADC_VREF                 AVCC
/*_SELECT_ADJUSTMENT_*/
/*_OPTIONS -> [ R_ADJUSTMENT ] , [ L_ADJUSTMENT ] _*/
#define ADC_ADJUSTMENT          L_ADJUSTMENT
/*_SELECT_PRESCALER_*/
/*_OPTIONS -> [PRESCALER _128 ] , [ PRESCALER_64 ] _*/
#define ADC_PRESCALER          PRESCALAR_64			
#endif /* MCAL_ADC_ADC_CFG_H_ */
