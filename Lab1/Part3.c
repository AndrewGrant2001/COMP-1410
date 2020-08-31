/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>

int power (int x, int n);

int main()
{
    int base, exponent; //variables declared
    printf("Enter an interger number (base): ");//prompts |
    scanf("%d", &base);
    printf("Enter an interger number (exponent): ");
    scanf("%d", &exponent);
    
    printf("%d to the power of %d is equal to %d\n", base, exponent, power(base, exponent)); //output
}

//function to calculate power with base and exponent from user
int power (int x, int n) {
    if (n <= 1) {
        return x;
    }
    return x * power(x, n-1);
}


