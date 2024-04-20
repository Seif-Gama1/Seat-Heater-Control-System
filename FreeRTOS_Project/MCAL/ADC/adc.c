/*  adc.c
 *  Created on: Apr 8, 2024
 *  Author: seif9
 */

#include "adc.h"

volatile static uint32 adc0Res = 0 ;    /* PB4 */
volatile static uint32 adc1Res = 0 ;    /* PB5 */

volatile static uint8  flag0      =0 ;
volatile static uint8  flag1      =0 ;

void ADC0SS3_handler(void){
    adc0Res = ADC0_ADCSSFIFO3 ;
    flag0=1;
    ADC0_ADCISC= (1<<3)       ;
}

void ADC1SS3_handler(void){
    adc1Res = ADC1_ADCSSFIFO3 ;
    flag1=1;
    ADC1_ADCISC = (1<<3)          ;
}

void ADC_ModuleInit(void){
    int delay;

    //activate clock for ADC 1 and 2
    SYSCTL_RCGCADC_REG |= (0x03);

    //active clock for portB (as I'll use ADC for pins PB4 and PB5)
    SYSCTL_RCGCGPIO_REG |= (0x02);

    //some delay until clock fully activated after executing the 2 above lines
    delay = SYSCTL_RCGCGPIO_REG;

    GPIO_PORTB_AFSEL_REG |= 0x30;

    GPIO_PORTB_DEN_REG &= ~(0x30);

    /*Disable the analog isolation circuit for all ADC input pins that are to be used by writing a 1 to
    the appropriate bits of the GPIOAMSEL register (see page 687) in the associated GPIO block.*/
    GPIO_PORTB_AMSEL_REG |= 0x30;

}
//seif is PE2, PE3
void ADC_SampleSeqInit(void){

    //disable sample sequencer number 3 (which will be used) for both ADCS
    ADC0_ADCACTSS &= 0xF7;
    ADC1_ADCACTSS &= 0xF7;

    // Configure trigger event for sample sequencer to Always
    ADC0_ADCEMUX |= ( (0xF)<<12);
    ADC1_ADCEMUX |= ( (0xF)<<12);

    // Configure analog input channels for ADC0 and ADC1
    ADC0_ADCSSMUX3 |= 10;   //Activate PB4 for ADC0
    ADC1_ADCSSMUX3 |= 11;   //Activate PB5 for ADC1

    /*5. For each sample in the sample sequence, configure the sample control bits in the
       * corresponding nibble in the ADCSSCTLn register. When programming the last nibble,
       * ensure that the END bit is set. Failure to set the END bit causes unpredictable behavior.*/
    ADC0_ADCSSCTL3 |= 0x06;
    ADC1_ADCSSCTL3 |= 0x06;

    /* 6. If interrupts are to be used, set the corresponding MASK bit
     * in the ADCIM register.*/
    ADC0_ADCIM |= 0x8;
    ADC1_ADCIM |= 0x8;

    /* Enable the sample sequencer logic by setting the corresponding ASENn bit in the
     * ADCACTSS register.*/
    ADC0_ADCACTSS |= 0x08   ;
    ADC1_ADCACTSS |= 0x08;

    //clear status bit by writing one into he corresponding bit position
    ADC0_ADCISC= (1<<3) ;
    ADC1_ADCISC= (1<<3) ;
}


void ADC_Init(void){
    PLL_Init();

    ADC_ModuleInit();
    ADC_SampleSeqInit();
}

uint32 ADC0_readChannel (void){
    ADC0_ADCPSSI|=(1<<3) ;
    while(flag0==0);

    flag0=0;

    return  adc0Res ;
}

uint32 ADC1_readChannel (void){
    ADC1_ADCPSSI|=(1<<3) ;
    while(flag1==0);

    flag1=0;

    return  adc1Res ;
}


