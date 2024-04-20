#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "tm4c123gh6pm_registers.h"
#include "std_types.h"
#include "gpio.h"

/*ADC0 module*/
#define ADC0_ADCACTSS (*((volatile unsigned long*)0x40038000))
#define ADC0_ADCEMUX (*((volatile unsigned long*)0x40038014))
#define ADC0_ADCSSMUX3 (*((volatile unsigned long*)0x400380A0))
#define ADC0_ADCSSCTL3 (*((volatile unsigned long*)0x400380A4))
#define ADC0_ADCPSSI (*((volatile unsigned long*)0x40038028))
#define ADC0_ADCISC (*((volatile unsigned long*)0x4003800C))
#define ADC0_ADCSSFIFO3 (*((volatile unsigned long*)0x400380A8))
#define ADC0_ADCSSFIFO3 (*((volatile unsigned long*)0x400380A8))
#define ADC0_ADCRIS (*((volatile unsigned long*)0x40038004))
#define ADC0_ADCIM  (*((volatile unsigned long*)0x40038008))
#define ADC0_ADCISC (*((volatile unsigned long*)0x40038000))

/*******************************************************************************************************************/
/*ADC1 module*/
#define ADC1_ADCACTSS (*((volatile unsigned long*)0x40039000))
#define ADC1_ADCEMUX (*((volatile unsigned long*)0x40039014))
#define ADC1_ADCSSMUX3 (*((volatile unsigned long*)0x400390A0))
#define ADC1_ADCSSCTL3 (*((volatile unsigned long*)0x400390A4))
#define ADC1_ADCPSSI (*((volatile unsigned long*)0x40039028))
#define ADC1_ADCISC (*((volatile unsigned long*)0x4003900C))
#define ADC1_ADCSSFIFO3 (*((volatile unsigned long*)0x400390A8))
#define ADC1_ADCRIS (*((volatile unsigned long*)0x40039004))
#define ADC1_ADCIM  (*((volatile unsigned long*)0x40039008))
#define ADC1_ADCISC (*((volatile unsigned long*)0x40039000))

/*******************************************************************************************************************/


/*
typedef enum{
    PE3=0,
    PE2,
    PE1,
    PE0,
    PD3,
    PD2,
    PD1,
    PD0,
    PE5,
    PE4,
    PB4,
    PB5

}ADC_PIN_ID;

typedef enum{
    ADC0=0,
    ADC1

}ADC_ID;
*/


void ADC_Init(void);
void ADC_SampleSeqInit(void);
void ADC_ModuleInit(void);

/* u32 ADC_Get_Data(ADC_PIN_ID PIN); */

#endif /* MCAL_ADC_ADC_H_ */
