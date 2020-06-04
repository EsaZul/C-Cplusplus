#include <stdio.h>
#include "stack_ll.h"
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void displayGrid(char *grid[]);

void floodGrid(char *grid[], int numRows, int numCols, char colorInput, Stack312 *s);

int numCols = 0;
int numRows = 0;

int main(int argc, char *argv[]) {
    Stack312 s;

    char fName[] = "fake_picture.txt";
//    strcpy(fName, argv[1]);

    const int MAX_ROWS = 25;                                 //we want the world to fit on one screen

    //array of strings that will hold the grid
    char *grid[MAX_ROWS];
  //  int numRows;
//    int numCols;
    char color;

    FILE *fptr;
    fptr = fopen(fName, "r"); //r is for read

    char buf[BUFSIZ];

    int i = 0;
    while (fgets(buf, sizeof(buf),fptr)) {

        grid[i] = (char *) malloc(strlen(buf));
        strcpy(grid[i], buf);
        //printf("%s", grid[i]);                                //debugger purposes, prints array in 1s and 0s
        i++;
    }

    numCols = strlen(grid[0])-1;                               //subtract 1 due to having the \n
    numRows = i;

  //  printf("%d \n", numCols);
    //printf("%d \n", numRows);

    fclose(fptr);

    displayGrid(grid);

    makeStack(&s);

    int totalRows = (int) sizeof(*grid) - 1;
    int totalCols = ((int) strlen(*grid)) - 1;


    for (int i = 0; i < 10; i++) {

        printf("Enter Row: ");
        while (scanf("%d", &numRows) != 1) {
            while (getchar() != '\n');
            printf("Not Accessible \n \nEnter Row: ");
        }

        printf("Enter Column: ");
        while (scanf("%d", &numCols) != 1) {
            while (getchar() != '\n');
            printf("Not Accessible \n \nEnter Column: ");
        }

        if ((numRows > (totalRows - 1) || (numCols > (totalCols - 1)) || (numRows < 0) || (numCols < 0))) {

            printf("Not Accessible \n \n");
        } else {

            printf("Enter Color: ");
            scanf(" %c", &color);

            printf("\n");

            floodGrid(grid, numRows, numCols, color, &s);

            system("clear");
            printf("\n");

            displayGrid(grid);

        }
    }
    return 0;
}


void displayGrid(char *grid[]) {
    //int totalRows = (int) sizeof(*grid) - 1;
//    int totalRows = (int) sizeof(*grid) - 1;
  //  int totalCols = ((int) strlen(*grid)) - 1;
//    printf("%d Cols", numCols);
  //  printf("%d Rows", numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void floodGrid(char *grid[], int numRows, int numCols, char colorInput, Stack312 *s) {

    char color = grid[numRows][numCols];

    StackEntry pixel;

    // loop until stack is empty
    while (color != colorInput) {

        displayGrid(grid);
        printf("\n");


        int i = 0; //index for rows
        int j = 0; //index for cols

        for (i = 0; i < numRows; i++) {                              //Note: +1 indicates next colm or next row
            for (j = 0; j < numCols; j++) {                          //Note: -1 indicates prev colom or prev row
                if (i == 0) {                                        //first row which has no top
                    if (j == 0) {                                    //top left corner, 3 neighbors to its right
                        if (color == grid[numRows + 1][numCols]) {
                            pixel.row = numRows + 1;
                            pixel.col = numCols;
                            pixel.color = grid[numRows + 1][numCols];
                            push(pixel, s);    // push pixel on to stack
                        }
                        if (color == grid[numRows][numCols + 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows][numCols + 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows + 1][numCols + 1]) {
                            pixel.row = numRows + 1;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows + 1][numCols + 1];
                            push(pixel, s);
                        }

                    } else if (j == (numCols - 1)) {                  //top right corner, 3 neighbors to its left
                        if (color == grid[numRows][numCols - 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows][numCols - 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows + 1][numCols]) {
                            pixel.row = numRows + 1;
                            pixel.col = numCols;
                            pixel.color = grid[numRows + 1][numCols];
                            push(pixel, s);
                        }
                        if (color == grid[numRows + 1][numCols - 1]) {
                            pixel.row = numRows + 1;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows + 1][numCols - 1];
                            push(pixel, s);
                        }
                    } else {                                         //exclude the row before
                        if (color == grid[numRows][numCols - 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows][numCols - 1];
                            push(pixel, s);

                        }
                        if (color == grid[numRows][numCols + 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows][numCols + 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows + 1][numCols - 1]) {
                            pixel.row = numRows + 1;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows + 1][numCols - 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows + 1][numCols]) {
                            pixel.row = numRows + 1;
                            pixel.col = numCols;
                            pixel.color = grid[numRows + 1][numCols];
                            push(pixel, s);
                        }
                        if (color == grid[numRows + 1][numCols + 1]) {
                            pixel.row = numRows + 1;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows + 1][numCols + 1];
                            push(pixel, s);
                        }
                    }
                } else if (i == (numRows - 1)) {                      //last row which has no bottom
                    if (j == 0) {                                     //bottom left corner, 3 neighbors to its right
                        if (color == grid[numRows - 1][numCols]) {
                            pixel.row = numRows - 1;
                            pixel.col = numCols;
                            pixel.color = grid[numRows - 1][numCols];
                            push(pixel, s);
                        }
                        if (color == grid[numRows][numCols + 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows][numCols + 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows - 1][numCols + 1]) {
                            pixel.row = numRows - 1;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows - 1][numCols + 1];
                            push(pixel, s);
                        }

                    } else if (j == (numCols - 1)) {                  //bottom right corner, 3 neighbors to its left
                        if (color == grid[numRows - 1][numCols]) {
                            pixel.row = numRows - 1;
                            pixel.col = numCols;
                            pixel.color = grid[numRows - 1][numCols];
                            push(pixel, s);
                        }
                        if (color == grid[numRows][numCols - 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows][numCols - 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows - 1][numCols - 1]) {
                            pixel.row = numRows - 1;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows - 1][numCols - 1];
                            push(pixel, s);
                        }
                    } else {                                         //excludes the row after
                        if (color == grid[numRows][numCols - 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows][numCols - 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows][numCols + 1]) {
                            pixel.row = numRows;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows][numCols + 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows - 1][numCols - 1]) {
                            pixel.row = numRows - 1;
                            pixel.col = numCols - 1;
                            pixel.color = grid[numRows - 1][numCols - 1];
                            push(pixel, s);
                        }
                        if (color == grid[numRows - 1][numCols]) {
                            pixel.row = numRows - 1;
                            pixel.col = numCols;
                            pixel.color = grid[numRows - 1][numCols];
                            push(pixel, s);
                        }
                        if (color == grid[numRows - 1][numCols + 1]) {
                            pixel.row = numRows - 1;
                            pixel.col = numCols + 1;
                            pixel.color = grid[numRows - 1][numCols + 1];
                            push(pixel, s);
                        }
                    }
                } else if (j == 0) {                                 //excludes neighbors on prior colm
                    if (color == grid[numRows + 1][numCols]) {
                        pixel.row = numRows + 1;
                        pixel.col = numCols;
                        pixel.color = grid[numRows + 1][numCols];
                        push(pixel, s);
                    }
                    if (color == grid[numRows + 1][numCols + 1]) {
                        pixel.row = numRows + 1;
                        pixel.col = numCols + 1;
                        pixel.color = grid[numRows + 1][numCols + 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows][numCols + 1]) {
                        pixel.row = numRows;
                        pixel.col = numCols + 1;
                        pixel.color = grid[numRows][numCols + 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows - 1][numCols + 1]) {
                        pixel.row = numRows - 1;
                        pixel.col = numCols + 1;
                        pixel.color = grid[numRows - 1][numCols + 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows - 1][numCols]) {
                        pixel.row = numRows - 1;
                        pixel.col = numCols;
                        pixel.color = grid[numRows - 1][numCols];
                        push(pixel, s);
                    }
                } else if (j == (numCols - 1)) {                     //excludes neighbors on next colm
                    if (color == grid[numRows + 1][numCols]) {
                        pixel.row = numRows + 1;
                        pixel.col = numCols;
                        pixel.color = grid[numRows + 1][numCols];
                        push(pixel, s);
                    }
                    if (color == grid[numRows + 1][numCols - 1]) {
                        pixel.row = numRows + 1;
                        pixel.col = numCols - 1;
                        pixel.color = grid[numRows + 1][numCols - 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows][numCols - 1]) {
                        pixel.row = numRows;
                        pixel.col = numCols - 1;
                        pixel.color = grid[numRows][numCols - 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows - 1][numCols - 1]) {
                        pixel.row = numRows - 1;
                        pixel.col = numCols - 1;
                        pixel.color = grid[numRows - 1][numCols - 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows - 1][numCols]) {
                        pixel.row = numRows - 1;
                        pixel.col = numCols;
                        pixel.color = grid[numRows - 1][numCols];
                        push(pixel, s);
                    }
                } else {                                            //regular 8 neighbors check
                    if (color == grid[numRows][numCols - 1]) {
                        pixel.row = numRows;
                        pixel.col = numCols - 1;
                        pixel.color = grid[numRows][numCols - 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows - 1][numCols - 1]) {
                        pixel.row = numRows - 1;
                        pixel.col = numCols - 1;
                        pixel.color = grid[numRows - 1][numCols - 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows - 1][numCols]) {
                        pixel.row = numRows - 1;
                        pixel.col = numCols;
                        pixel.color = grid[numRows - 1][numCols];
                        push(pixel, s);
                    }
                    if (color == grid[numRows - 1][numCols + 1]) {
                        pixel.row = numRows - 1;
                        pixel.col = numCols + 1;
                        pixel.color = grid[numRows - 1][numCols + 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows][numCols + 1]) {
                        pixel.row = numRows;
                        pixel.col = numCols + 1;
                        pixel.color = grid[numRows][numCols + 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows + 1][numCols + 1]) {
                        pixel.row = numRows + 1;
                        pixel.col = numCols + 1;
                        pixel.color = grid[numRows + 1][numCols + 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows + 1][numCols]) {
                        pixel.row = numRows + 1;
                        pixel.col = numCols + 1;
                        pixel.color = grid[numRows + 1][numCols + 1];
                        push(pixel, s);
                    }
                    if (color == grid[numRows + 1][numCols - 1]) {
                        pixel.row = numRows + 1;
                        pixel.col = numCols - 1;
                        pixel.color = grid[numRows + 1][numCols - 1];
                        push(pixel, s);
                    }
                }
            }
        }
        grid[numRows][numCols] = colorInput;

        //is the stack empty?
        if(isEmpty(*s) == false){
            StackEntry popEntry = pop(s);
            numRows = popEntry.row;
            numCols = popEntry.col;
        }
        else {
            break;
        }
    }
}


/*int main() {
    printf("Hello, World!\n");

  Stack Debugger

    Stack312 s2;
    makeStack(&s2);

    if (isEmpty(s2))
        printf("empty\n");
    else
        printf("not empty\n");

    Pixel p2 = {5,9,'P'};
    Pixel p3 = {4,4,'G'};

    if(!isFull(s2)) {
        push(p2, &s2);
        push(p3, &s2);
    }
    else {
        printf("FULL!\n");
    }


    if (isEmpty(s2))
        printf("again empty\n");
    else
        printf("again not empty\n");

    Pixel p;
    p = pop(&s2);
    printf("s2 %d %d %c\n",p.row, p.col, p.color);

    return 0;
}
*/
