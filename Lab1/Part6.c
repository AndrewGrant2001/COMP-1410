/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomgen(int row, int col, int a[row][col], int top, int bottom);

int main()
{
    int i, j, max, min;
    
    printf("Enter number of rows: ");
    scanf("%d", &i);
    printf("Enter number of columns: ");
    scanf("%d", &j);
    
    printf("Enter a maximum number: ");
    scanf("%d", &max);
    printf("Enter a minimum number: ");
    scanf("%d", &min);
    
    int array[i][j];
    
    randomgen(i, j, array, max, min);
   
    for (int q = 0; q < i; q++){
        for (int z = 0; z < j; z++){
           printf("[%2d] ", array[q][z]);
           if(z == (j-1)){
               puts("");
           }
        }
    }
}

int randomgen(int row, int col, int a[row][col], int top, int bottom){
    srand(time(0));
    for (int n = 0; n < row; n++){
        for (int m = 0; m < col; m++){
            a[n][m] = rand() % (top - bottom + 1) + bottom;
        }
    } 
}


