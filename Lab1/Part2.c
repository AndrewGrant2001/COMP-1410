/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>

int sum (int n);

int main()
{
    int num;
    printf("Enter an integer number: \n");
    scanf("%d", &num);
    
    printf("The sum from 1 to %d is equal to %d\n", num, sum(num));
}

int sum (int n) {
    if (n <= 1){
        return 1;
    }
    return n + sum(n - 1); 
}

