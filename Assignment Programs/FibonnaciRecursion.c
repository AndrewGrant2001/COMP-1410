/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
//#include <time.h>

//function to calculate fibonnaci sequence spot
int fibonnaci(int n, int a, int b);

int main()
{
    int num, n1, n2 = 0, n3 = 1;//Declaring Variables
    printf("Enter number to calculate fibonnaci: ");//prompt
    scanf("%d", &num);
    printf("The answer is equal to %d using Recursion\n", fibonnaci(num, 0, 1));//output
}

int fibonnaci(int n, int a, int b){
    if (n == 0) {
        return a;
    }
    else {
        fibonnaci(n - 1, b, b + a);
    }
}

