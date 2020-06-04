// IO.c
// This software configures the switch and LED
// You are allowed to use any switch and any LED, 
// although the Lab suggests the SW1 switch PF4 and Red LED PF1
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: March 30, 2018
// Last Modified:  change this or look silly
// Lab number: 7


#include "../inc/tm4c123gh6pm.h"
#include <stdint.h>

//------------IO_Init------------
// Initialize GPIO Port for a switch and an LED
// Input: none
// Output: none
void IO_Init(void) {																						// PF4 is button, PF2 is heartbeat
	
	uint8_t nop = 0;
	SYSCTL_RCGCGPIO_R |= 0x20;																		// start clock for Port F
	nop += 0;
	nop += 0;
	
	GPIO_PORTF_DEN_R |= 0x14;																			// enables PF4 button and PF2 heartbeat
	GPIO_PORTF_DIR_R &= ~0x10;																		// makes PF4 input
	GPIO_PORTF_DIR_R |= 0x04;																			// makes PF3 output
	GPIO_PORTF_PUR_R |= 0x10;																			// PF4 positive logic
	
}

//------------IO_HeartBeat------------
// Toggle the output state of the LED.
// Input: none
// Output: none
void IO_HeartBeat(void) {																				// PF2 is heartbeat
	
	for (unsigned int delay = 0; delay < 320000; delay++){}				// delay to see heartbeat
	GPIO_PORTF_DATA_R ^= 0x08;
		
}

//------------IO_Touch------------
// wait for release and press of the switch
// Delay to debounce the switch
// Input: none
// Output: none
void IO_Touch(void) {																						//wait for release; delay for 20ms; and then wait for press
	
	do {} while ((GPIO_PORTF_DATA_R & 0x10) == 0x00);							// wait for release
		
	for (unsigned int delay = 0; delay < 1600000; delay ++){}			// delay for 20 ms for debounce
		
	do {} while ((GPIO_PORTF_DATA_R & 0x10) == 0x10);							// wait for buton press
}  
