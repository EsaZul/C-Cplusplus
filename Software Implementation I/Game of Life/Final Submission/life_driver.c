//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Eduardo Saul Ruiz, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Eduardo Saul Ruiz
 * email address: esruiz39@utexas.edu
 * UTEID: esr668
 * Section 5 digit ID: 16020
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "life.h"
#include <time.h>

void delay(unsigned int ms) {
    clock_t goal = ms +clock();
    while (goal > clock());
}

int main(int argc, char *argv[]) {

   //edit these two lines and use the command line arguments
   char fName[] = "world.txt";
   strcpy(fName,argv[1]);
   //const int numGenerations  = 2;                         //set to a smaller number for debugging
   int numGenerations = atoi(argv[2]);
    
   const int MAX_ROWS = 80;                                 //we want the world to fit on one screen

   //array of strings that will hold the grid
   char *world[MAX_ROWS];
   int numRows;
   int numCols;

   populateWorld(fName, world, &numRows, &numCols);

   showWorld(world, numRows, numCols);

   for (int iteration = 0; iteration < numGenerations; iteration++) {

       delay(500000);

       system("clear"); //Linux only

       printf("------------------------------- \n");

       printf("Iteration %d \n", (iteration+1));

       iterateGeneration(world, numRows, numCols);

       showWorld(world, numRows, numCols);
  }

  return 0;
}



