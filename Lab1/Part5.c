/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define N 8
#define M 8

char knightmoves(char a[N][M], int x, int y);

int main()
{
    char chessboard[N][M]; 
    int row, col;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            chessboard[i][j] = '-';
        }
    }
    
    do {
        printf("Enter a row and column in range 0-7 inclusive: (Ex. 0 1) \n");
        scanf("%d %d", &row, &col);
    } while (row < 0 || row > 7 || col < 0 || col > 7);
    
    chessboard[row][col] = 'K';
    
    knightmoves(chessboard, row, col);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("|%c", chessboard[i][j]);
            if (j == 7){
                printf("|\n");
                //printf("----------------\n");
            }
        }
    }
    puts("K ~ Represents Knights Place on Board");
    puts("o ~ Represents places where Knight can move");
    puts("- ~ Represents places the Knight cannot move.");
}

char knightmoves(char a[N][M], int x, int y){
    for(int k = 0; k <= 7; k++){
        for (int n = 0; n <= 7; n++){
            if(a[k+2][n+1] == 'K' && k+2 > -1 && k+2 < 8 && n+1 > 0 && n+1 < 8){
                a[k][n] = 'o';
            }
            else if(a[k-2][n+1] == 'K' && k-2 > -1 && k-2 < 8 && n+1 > -1 && n+1 < 8){
                a[k][n] = 'o';
            }
            else if(a[k-2][n-1] == 'K' && k-2 > -1 && k-2 < 8 && n-1 > -1 && n-1 < 8){
                a[k][n] = 'o';
            }
            else if(a[k+2][n-1] == 'K' && k+2 > -1 && k+2 < 8 && n-1 > -1 && n-1 < 8){
                a[k][n] = 'o';
            }
            else if(a[k+1][n+2] == 'K' && k+1 > -1 && k+1 < 8 && n+2 > -1 && n+2 < 8){
                a[k][n] = 'o';
            }
            else if(a[k-1][n+2] == 'K' && k-1 > -1 && k-1 < 8 && n+2 > -1 && n+2 < 8){
                a[k][n] = 'o';
            }
            else if(a[k-1][n-2] == 'K' && k-1 > -1 && k-1 < 8 && n-2 > -1 && n-2 < 8){
                a[k][n] = 'o';
            }
            else if(a[k+1][n-2] == 'K' && k+1 > -1 && k+1 < 8 && n-2 > -1 && n-2 < 8){
                a[k][n] = 'o';
            }
        }
    }
    return a;
}

