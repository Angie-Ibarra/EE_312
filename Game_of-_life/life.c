#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "life.h"

void populateWorld(char fName[], char *grid[], int *numRows, int *numCols) {
    //reads file
    FILE *fp;
    fp = fopen(fName, "r");
    char c;
    int col = 0;
    do {
        c = fgetc(fp);
        if (c == '\n') {
            break;
        }
        col++;
    } while (c != EOF);
    fclose(fp);
    *numCols = col;
    printf("%d\n", *numCols);

    fp = fopen(fName, "r");
    char * str = NULL;
    int row = 0;
    do{
        grid[row] = malloc(col);
        fgets(grid[row], col+1, fp);
        row++;
    } while((fgets(str, col+1, fp)) != NULL);


    *numRows = row;
    fclose(fp);
}

void showWorld(char *grid[], int numRows, int numCols){
    for(int i = 0; i < numRows; i++){

        for(int j = 0; j < numCols; j++){
            if(grid[i][j] == '1'){
                grid[i][j] = '*';
            }
            if(grid[i][j] == '0'){
                grid[i][j] = '.';
            }
        }
    }
    for(int k = 0; k <  numRows; k++){
        printf("%s\n", grid[k]);
    }
}

void iterateGeneration(char *grid[], int numRows, int numCols){
    char temp[numRows][numCols];
    for(int i = 0; i < numRows; i++){
        for(int j =0; j < numCols; j++){
            int numNeighbors = 0;
            if(grid[i-1][j] == '*'){
                numNeighbors++;
            }
            if(grid[i][j+1] == '*'){
                numNeighbors++;
            }
            if(grid[i+1][j] == '*'){
                numNeighbors++;
            }
            if(grid[i][j-1] == '*'){
                numNeighbors++;
            }
            if(numNeighbors == 1 || numNeighbors < 1){
                temp[i][j] = '.';
            }
            if(numNeighbors == 2 && grid[i][j] == '*'){
                temp[i][j] = '*';
            }
            if(numNeighbors == 2 && grid[i][j] == '.'){
                temp[i][j] = '.';
            }
            if(numNeighbors == 3){
                temp[i][j] = '*';
            }
            if(numNeighbors == 4 || numNeighbors > 4){
                temp[i][j] = '.';
            }
        }
    }
    for(int k = 0; k < numRows; k++){
        for(int c = 0; c < numCols; c++){
            grid[k][c] = temp[k][c];
        }
    }
}