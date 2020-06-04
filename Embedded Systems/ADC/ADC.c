// ADC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Last Modified: 11/6/2018
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// ADC initialization function 
// Input: none
// Output: none
// measures from PD2, analog channel 5
void ADC_Init(void){
	
	SYSCTL_RCGCGPIO_R|=0x08;  							//activate clock for port D
	while ((SYSCTL_RCGCGPIO_R&0x08)==0){};	//wait for clock to stabilize
	GPIO_PORTD_DIR_R&= ~0x04;								//PD2 is set as an input
	GPIO_PORTD_AFSEL_R|=0x04;								//enable alternate function on PD2
	GPIO_PORTD_DEN_R&= ~0x04;								//disable digital IO on PD2
	GPIO_PORTD_AMSEL_R|=0x04;								//activate analog function on PD2
		
	SYSCTL_RCGCADC_R|=0x01;									//activate ADC0 clock
	while ((SYSCTL_RCGCADC_R&0x01)==0){};		//wait for clock to stabilize
	ADC0_PC_R=0x01;													//max sample rate of 125k/second
	ADC0_SSPRI_R=0x0123;										//set sequencer priority
	ADC0_ACTSS_R&= ~0x0008;									//need to disable sample sequencer before configuring it
	ADC0_EMUX_R&= ~0xF000;									//NOT NEEDED?? ADC will be triggered by software start
	ADC0_SSMUX3_R&= 0xFFFFFFF0;
	ADC0_SSMUX3_R+=5;												//set channel 5
	ADC0_SSCTL3_R=0x0006;										//specifies that ADC will measure voltage, use busy-wait
	ADC0_IM_R&= ~0x0008;										//disable sequencer interrupts
	ADC0_ACTSS_R|=0x0008;										//enable sample sequencer
		
}

//------------ADC_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
// measures from PD2, analog channel 5
uint32_t ADC_In(void){
	unsigned long result;										//unsigned long??? for main2???
	// CHANGE NAMES
	ADC0_PSSI_R=0x0008;											//initiate sequencer 3
	while ((ADC0_RIS_R&0x0008)==0){};				//wait for conversion indicated by RIS bit
	result=ADC0_SSFIFO3_R & 0xFFF;					//get 12-bit result
	ADC0_ISC_R=0x0008;											//clears RIS bit
	return result;
	
}


