// StepperMotorController.c starter file EE319K Lab 5
// Runs on TM4C123
// Finite state machine to operate a stepper motor.  
// Jonathan Valvano
// October 5, 2018

// Hardware connections (External: two input buttons and four outputs to stepper motor)
//  PE5 is Speed input  (1 means pressed, 0 means not pressed)
//  PE4 is Wash input  (1 means pressed, 0 means not pressed)
//  PB3-0 are stepper motor outputs 
//  PF1 PF2 or PF3 control the LED on Launchpad used as a heartbeat
//  PB4 is LED output (1 activates external LED on protoboard)

#include "SysTick.h"
#include "TExaS.h"
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#define STEPPER       							(*((volatile uint32_t *)0x400053FC))
#define timewait 	  50

void EnableInterrupts(void);
typedef const struct State {
  uint32_t Out; 
  uint32_t wait;  // 10 ms units
  const struct State *Next[4];
} STyp; 

#define Go5A 	 &FSM[0]
#define Go6A 	 &FSM[1]
#define Go10A  &FSM[2]
#define Go9A	 &FSM[3]
#define Go5B 	 &FSM[4]
#define Go6B 	 &FSM[5]
#define Go10B  &FSM[6]
#define Go9B	 &FSM[7]
#define Back5A 	 &FSM[8]
#define Back9A 	 &FSM[9]
#define Back10A	 &FSM[10]
#define Back6A	 &FSM[11]
#define Back5B 	 &FSM[12]
#define Back9B 	 &FSM[13]
#define Back10B	 &FSM[14]
#define Back6B	 &FSM[15]

#define GB5A  &FSM[16]
#define GB6A  &FSM[17]
#define GB5B  &FSM[18]
#define GB6B  &FSM[19]
#define GB5C  &FSM[20]
#define GB9C  &FSM[21]
#define GB5D  &FSM[22]
#define GB9D  &FSM[23]

STyp FSM[24] = {
 {0x05,timewait,{Go5A,  	Go6A,			GB5A,			GB5A}}, 
 {0x06,timewait,{Go10A, 	Go10A,		Go10A,		Go10A}},
 {0x0A,timewait,{Go9A,		Go9A,			Go9A,			Go9A}},
 {0x09,timewait,{Go5B,		Go5B,			GB5B,			GB5B}},
 {0x05,timewait,{Go6B,		Go6B,			Go6B,			Go6B}},
 {0x06,timewait,{Go10B,		Go10B,		Go10B,		Go10B}},
 {0x0A,timewait,{Go9B,		Go9B,			Go9B,			Go9B}},
 {0x09,timewait,{Back5A,	Back5A,		GB5C,			GB5C}},
 {0x05,timewait,{Back9A,	Back9A,		Back9A,		Back9A}},
 {0x09,timewait,{Back10A,	Back10A,	Back10A,	Back10A}},
 {0x0A,timewait,{Back6A,	Back6A,		Back6A,		Back6A}},
 {0x06,timewait,{Back5B,	Back5B,		GB5D,			GB5D}},
 {0x05,timewait,{Back9B,	Back9B,		Back9B,		Back9B}},
 {0x09,timewait,{Back10B,	Back10B,	Back10B,	Back10B}},
 {0x0A,timewait,{Back6B,	Back6B,		Back6B,		Back6B}},
 {0x06,timewait,{Go5A,		Go5A,			Go5A,			Go5A}},
 
 {0x45,timewait,{GB6A,		GB6A,			GB6A,			GB6A}}, 		//GB5A
 {0x46,timewait,{Go10A,		Go10A,		Go10A,		Go10A}},		//GB6A
 {0x45,timewait,{GB6B,		GB6B,			GB6B,			GB6B}},			//GB5B
 {0x46,timewait,{Go10B,		Go10B,		Go10B,		Go10B}},		//GB6B
 
 {0x45,timewait,{GB9C,		GB9C,			GB9C,			GB9C}},			//GB5C
 {0x49,timewait,{Back10A,	Back10A,	Back10A,	Back10A}},	//GB9C
 {0x45,timewait,{GB9D,		GB9D,			GB9D,			GB9D}},			//GB5D
 {0x49,timewait,{Back10B,	Back10B,	Back10B,	Back10B}},	//GB9D
 };
	STyp *Pt;  // state pointer 
	uint32_t Input; 
int main(void){ 
	volatile int32_t delay; 
// you initialize your system here
	SYSCTL_RCGCGPIO_R |= 0x02;
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTB_DIR_R |= 0x4F;
	GPIO_PORTB_DIR_R &= 0xFFFFFFCF;
	GPIO_PORTB_DEN_R |= 0x7F;	
	TExaS_Init(1);    // activate logic analyzer port B and set system clock to 80 MHz
	SysTick_Init();	
  Pt = Go5A; // start state
	EnableInterrupts();
  while(1) {
    STEPPER = Pt->Out;  // step
    SysTick_Wait10ms(Pt->wait);
    Input = ((STEPPER&0x30)>>4);  // read buttons
    Pt = Pt->Next[Input];
	}
}
