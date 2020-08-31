/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>

int fibonnaci (int a);//Declaring

int main()
{
    int num, n1, n2 = 0, n3 = 1;//Declaring Variables
    printf("Enter number to calculate fibonnaci: ");//prompt
    scanf("%d", &num);
    printf("The answer is equal to %d using Recursion\n", fibonnaci(num));
    
    //if statements to catch for less than 0 or equals 1
    if (num <= 0) {
        n3 = 0;
    }
    else if (num == 1) {
        n3 = 1;
    }
    
    //loop to calculate fibonnaci number
    for(int i = 1; i < num; ++i) {
        n1 = n2;
        n2 = n3;
        n3 = n1 + n2;
    }
    
    printf("The answer is equal to %d using Iteration\n", n3);
}

//function to return fibonnaci number
int fibonnaci (int a){
    if (a <= 0){
        return 0;
    }
    else if (a == 1){
        return 1;
    }
    else {
        return fibonnaci(a - 1) + fibonnaci(a - 2);
    }
}



