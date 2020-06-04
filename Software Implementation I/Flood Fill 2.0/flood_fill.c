#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void makeGrid(char fName[], char *grid[], int *numRows, int *numCols);
void showGrid(char *grid[], int numRows, int numCols);
void updateGrid(char *grid[], int numRows, int numCols, char color, char colorInput, int x, int y);






int main(int argc, char *argv[]) {

    char fName[] = "fake.txt";
    strcpy(fName,argv[1]);

    const int MAX_ROWS = 25; // Maximum size of screen

    //array of strings that will hold the grid
    char *grid[MAX_ROWS];
    int numRows, numCols;
    int x;
    int y;
    char color;
    char colorInput;

    makeGrid(fName, grid, &numRows, &numCols);

    showGrid(grid, numRows, numCols);           //Everything works from here up


    for(int i=0; i<10; i++) {

        printf("\nRow: ");
        while (scanf("%d", &x) != 1)
        {
            while (getchar() != '\n');
            printf("Parameters outside grid \n \nRow: ");
        }

        printf("Column: ");
        while (scanf("%d", &y) != 1)
        {
            while (getchar() != '\n');
            printf("Parameters outside grid \n \nColumn: ");
        }

        if ( (x > numRows) || (y > numCols) || (x < 0) || (y < 0) ){

            printf("Parameters outside grid \n \n");
        }

        else {

            printf("Color: ");
            scanf(" %c", &colorInput);

            printf("\n");

            color = grid[x][y];    //color contains original color
            grid[x][y] = colorInput;
            updateGrid(grid, numRows, numCols, color, colorInput, x, y);

            system("clear");
            printf("\n");

            showGrid(grid, numRows, numCols);

        }
    }
    return 0;
}

void makeGrid(char fName[], char *grid[], int *numRows, int *numCols) {

    FILE *fptr;
    fptr = fopen(fName, "r"); //r is for read
    if (fptr == NULL) {                                          //debugger to see if file was read
        printf("you screwed nup!\n");
        exit(-1);
    }
    else {
        printf("success!\n");
    }

    char buf[BUFSIZ];

    int i = 0;
    while (fgets(buf, sizeof(buf), fptr)) {

        grid[i] = (char *) malloc(strlen(buf));
        strcpy(grid[i], buf);
        //printf("%s", grid[i]);                                //debugger purposes, prints array in 1s and 0s
        i++;
    }

    *numCols = strlen(grid[0]) - 1;                               //subtract 1 due to having the \n
    *numRows = i;

    //printf("Cols: %d \n", *numCols);
    //printf("Rows: %d \n", *numRows);
}


void showGrid(char *grid[], int numRows, int numCols){
    int i = 0;
    printf("%d \n", numCols);
    printf("%d \n", numRows);

    while(i < numRows) {

        printf("%s", grid[i]);                                  //prints/shows world
        i++;
    }
}


void updateGrid(char *grid[], int numRows, int numCols, char color, char colorInput, int x, int y){


    if( color != colorInput ) {
        if (x == 0) {                                        //first row which has no top
            if (y == 0) {                                    //top left corner
                if (color == grid[x+1][y]) {
                    grid[x+1][y] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x+1), y);
                }
                if (color == grid[x][y+1]) {
                    grid[x][y+1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y+1));
                }
                if (color == grid[x+1][y+1]) {
                    grid[x+1][y+1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y+1));
                }
            }
            else if (y == (numCols-1)) {                  //top right corner
                if (color == grid[x][y-1]) {
                    grid[x][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y-1));
                }
                if (color == grid[x+1][y]) {
                    grid[x+1][y] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x+1), y);
                }
                if (color == grid[x+1][y-1]) {
                    grid[x+1][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y-1));
                }
            }
            else {                                         //top side
                if (color == grid[x][y-1]) {
                    grid[x][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y-1));
                }
                if (color == grid[x][y+1]) {
                    grid[x][y+1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y+1));
                }
                if (color == grid[x+1][y-1]) {
                    grid[x+1][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y-1));
                }
                if (color == grid[x+1][y]) {
                    grid[x+1][y] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x+1), y);
                }
                if (color == grid[x+1][y+1]) {
                    color = grid[x+1][y+1];
                    updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y+1));
                }
            }
        }
        else if (x == (numRows-1)){
            if (y == 0) {                                   //bot left corner
                if (color == grid[x-1][y]) {
                    grid[x-1][y] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x-1), y);
                }
                if (color == grid[x][y+1]) {
                    grid[x][y+1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y+1));
                }
                if (color == grid[x-1][y+1]) {
                    grid[x-1][y+1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y+1));
                }
            }
            else if (y == (numCols-1)) {                    //bot right corner
                if (color == grid[x][y-1]) {
                    grid[x][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y-1));
                }
                if (color == grid[x-1][y]) {
                    grid[x-1][y] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x-1), y);
                }
                if (color == grid[x-1][y-1]) {
                    grid[x-1][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y-1));
                }
            }
            else {                                         //bot side
                if (color == grid[x][y-1]) {
                    grid[x][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y-1));
                }
                if (color == grid[x][y+1]) {
                    grid[x][y+1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, x, (y+1));
                }
                if (color == grid[x-1][y-1]) {
                    grid[x-1][y-1] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y-1));
                }
                if (color == grid[x-1][y]) {
                    grid[x-1][y] = colorInput;
                    updateGrid(grid, numRows, numCols, color, colorInput, (x-1), y);
                }
                if (color == grid[x-1][y+1]) {
                    color = grid[x-1][y+1];
                    updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y+1));
                }
            }
        }
        else if (y == 0){                                   //left side
            if (color == grid[x-1][y]) {
                grid[x-1][y] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x-1), y);
            }
            if (color == grid[x+1][y]) {
                grid[x+1][y] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x+1), y);
            }
            if (color == grid[x-1][y+1]) {
                grid[x-1][y+1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y+1));
            }
            if (color == grid[x][y+1]) {
                grid[x][y+1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, x, (y+1));
            }
            if (color == grid[x+1][y+1]) {
                color = grid[x+1][y+1];
                updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y+1));
            }
        }
        else if (y == (numCols-1)){                         //right side
            if (color == grid[x-1][y]) {
                grid[x-1][y] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x-1), y);
            }
            if (color == grid[x+1][y]) {
                grid[x+1][y] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x+1), y);
            }
            if (color == grid[x-1][y-1]) {
                grid[x-1][y-1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y-1));
            }
            if (color == grid[x][y-1]) {
                grid[x][y-1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, x, (y-1));
            }
            if (color == grid[x+1][y-1]) {
                color = grid[x+1][y-1];
                updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y-1));
            }
        }
        else {                                              //all 8 neighbors
            if (color == grid[x-1][y-1]) {
                grid[x-1][y-1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y-1));
            }
            if (color == grid[x-1][y]) {
                grid[x-1][y] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x-1), y);
            }
            if (color == grid[x-1][y+1]) {
                grid[x-1][y+1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x-1), (y+1));
            }
            if (color == grid[x][y-1]) {
                grid[x][y-1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, x, (y-1));
            }
            if (color == grid[x][y+1]) {
                grid[x][y+1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, x, (y+1));
            }
            if (color == grid[x+1][y-1]) {
                grid[x+1][y-1] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y-1));
            }
            if (color == grid[x+1][y]) {
                grid[x+1][y] = colorInput;
                updateGrid(grid, numRows, numCols, color, colorInput, (x+1), y);
            }
            if (color == grid[x+1][y+1]) {
                color = grid[x+1][y+1];
                updateGrid(grid, numRows, numCols, color, colorInput, (x+1), (y+1));
            }
        }
    }
}

