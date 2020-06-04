// Fifo.c
// Runs on LM4F120/TM4C123
// Provide functions that implement the Software FiFo Buffer
// Last Modified: November 14, 2018
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#define size 9

int static put;																			// uint32_t??
int static get;																			// uint32_t??
int static Fifo[size];															// uint32_t?? or int32_t??, capatilized??


// *********** Fifo_Init**********
// Initializes a software FIFO of a
// fixed size and sets up indexes for
// put and get operations
void Fifo_Init() {
	put = 0;
	get = 0;
}

// *********** Fifo_Put**********
// Adds an element to the FIFO
// Input: Character to be inserted
// Output: 1 for success and 0 for failure
//         failure is when the buffer is full
uint32_t Fifo_Put(char data) {
	
	if (((put + 1) % size) == get)										// if buffer full, return error
		return 0;
	
	Fifo[put] = data;																	// else store new information and increment put index
	put = (put + 1) % size;
	
	return 1;
}

// *********** FiFo_Get**********
// Gets an element from the FIFO
// Input: Pointer to a character that will get the character read from the buffer
// Output: 1 for success and 0 for failure
//         failure is when the buffer is empty
uint32_t Fifo_Get(char *datapt){
	if (put == get)																		// if buffer empty, return error
		return 0;
	
	*datapt = Fifo[get];															// retrieve current data
	get = (get + 1) % size;														// next data location
	
	return 1;
}

