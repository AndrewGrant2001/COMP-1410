/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int tempF;
    float tempC;
    
    do {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%d", &tempF);
    } while(tempF < 0 || tempF > 212);
    
    tempC = 5.0/9.0 * (float)(tempF - 32);
    
    printf("%10d °F |%+10.3f °C\n", tempF, tempC);
}


