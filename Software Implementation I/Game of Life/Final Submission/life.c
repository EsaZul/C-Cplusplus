
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "life.h"


void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
    FILE *fptr;
    fptr = fopen(fname, "r"); //r is for read
/*
    if (fptr == NULL) {                                          //debugger to see if file was read
        printf("you screwed nup!\n");
        exit(-1);
    }
    else {
        printf("success!\n");
    }
*/
    char buf[BUFSIZ];

    int i = 0;
    while (fgets(buf, sizeof(buf),fptr)) {

        grid[i] = (char *) malloc(strlen(buf));
        strcpy(grid[i], buf);
        //printf("%s", grid[i]);                                //debugger purposes, prints array in 1s and 0s
        i++;
    }

    *numCols = strlen(grid[0])-1;                               //subtract 1 due to having the \n
    *numRows = i;
}

void showWorld(char *grid[], int numRows, int numCols){
    int i = 0;
    int j = 0;

    while(i < numRows) {                                         //Replaces the 1's and 0s w/ * and .

        while (j < numCols) {

            if (grid[i][j] == '0') {
                grid[i][j] = '.';
            }
            if (grid[i][j] == '1') {
                grid[i][j] = '*';
            }
            j++;
        }
        printf("%s", grid[i]);                                  //prints/shows world
        i++;
        j = 0;                                                  //resets cols
    }
}

void iterateGeneration(char *grid[], int numRows, int numCols) {
    int tempGrid[numRows][numCols];                             //used to store neighbors in an array

    int i = 0; //index for rows
    int j = 0; //index for cols
    int k = 0; //row increment
    int l = 0; //cols increment
    int n = 0; //num of neighbors

    for (i = 0; i < numRows; i++) {                              //Note: +1 indicates next colm or next row
        for (j = 0; j < numCols; j++) {                          //Note: -1 indicates prev colom or prev row
            if (i == 0) {                                        //first row which has no top
                if (j == 0) {                                    //top left corner, 3 neighbors to its right

                    if (grid[i][j + 1] == '*') {
                        n++;
                    }
                    if (grid[i + 1][j] == '*') {
                        n++;
                    }
                    if (grid[i + 1][j + 1] == '*') {
                        n++;
                    }

                } else if (j == (numCols - 1)) {                  //top right corner, 3 neighbors to its left

                    if (grid[i][j - 1] == '*') {
                        n++;
                    }
                    if (grid[i + 1][j] == '*') {
                        n++;
                    }
                    if (grid[i + 1][j - 1] == '*') {
                        n++;
                    }
                } else {                                         //exclude the row before
                    for (k = 0; k < 2; k++) {
                        for (l = -1; l < 2; l++) {
                            if ((k != 0) || (l != 0)) {
                                if (grid[i + k][j + l] == '*') {
                                    n++;
                                }
                            }
                        }
                    }
                }
            } else if (i == (numRows - 1)) {                      //last row which has no bottom
                if (j == 0) {                                     //bottom left corner, 3 neighbors to its right
                    if (grid[i - 1][j] == '*') {
                        n++;
                    }
                    if (grid[i][j + 1] == '*') {
                        n++;
                    }
                    if (grid[i - 1][j + 1] == '*') {
                        n++;
                    }

                } else if (j == (numCols - 1)) {                  //bottom right corner, 3 neighbors to its left
                    if (grid[i][j - 1] == '*') {
                        n++;
                    }
                    if (grid[i - 1][j] == '*') {
                        n++;
                    }
                    if (grid[i - 1][j - 1] == '*') {
                        n++;
                    }
                } else {                                         //excludes the row after
                    for (k = -1; k < 1; k++) {
                        for (l = -1; l < 2; l++) {
                            if ((k != 0) || (l != 0)) {
                                if (grid[i + k][j + l] == '*') {
                                    n++;
                                }
                            }
                        }
                    }
                }
            } else if (j == 0) {                                 //excludes neighbors on prior colm
                for (k = -1; k < 2; k++) {
                    for (l = 0; l < 2; l++) {
                        if ((k != 0) || (l != 0)) {
                            if (grid[i + k][j + l] == '*') {
                                n++;
                            }
                        }
                    }
                }
            } else if (j == (numCols - 1)) {                     //excludes neighbors on next colm
                for (k = -1; k < 2; k++) {
                    for (l = -1; l < 1; l++) {
                        if ((k != 0) || (l != 0)) {
                            if (grid[i + k][j + l] == '*') {
                                n++;
                            }
                        }
                    }
                }
            } else {                                            //regular 8 neighbors check
                for (k = -1; k < 2; k++) {
                    for (l = -1; l < 2; l++) {
                        if ((k != 0) || (l != 0)) {
                            if (grid[i + k][j + l] == '*') {
                                n++;
                            }
                        }
                    }
                }
            }
            tempGrid[i][j] = n;                                 //stores neighbors in array, corresponds to grid
            n = 0;                                              //resets neighbor counts
        }
    }
/*
    for (int c = 0; c < numRows; c++) {                         //prints neighbors in array, used for debugging
        for (int d = 0; d < numCols; d++) {
            printf("%d", tempGrid[c][d]);
        }
        printf("\n");
    }
    printf("\n");
*/
    for (i=0; i < numRows; i++) {                        //prints new generation corresponding to neighbor tempGrid
        for (j=0; j < numCols; j++) {
            if (tempGrid[i][j] == 3) {                          //Game of Life Rules
                grid[i][j] = '*';
            } else if ((tempGrid[i][j] < 2) || (tempGrid[i][j] > 3)) {
                grid[i][j] = '.';
            }
        }
        //printf("%s", grid[i]);                                //prints the newgeneration grid, used for debugging
    }
}

