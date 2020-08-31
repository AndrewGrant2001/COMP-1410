/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>

int main()
{
    int y = 5;
    int *yPtr = &y;
    
    printf("%d\n", yPtr);
    printf("%i\n", yPtr);
    printf("%o\n", yPtr);
    printf("%u\n", yPtr);
    printf("%x\n", yPtr);
    printf("%hd\n", yPtr);
    printf("%ld\n", yPtr);
    printf("%p\n", yPtr);
    
    /* 
    All integer specifiers create warnings of wrong type. 
    'd' and 'i' return same value and sometimes 'u' returns same value
    long int returns the decimal number of the address and can be convert to decimal to get the hexdecimal location
    'x' returns the last 8 digits of the hexdecimal pointer address
    'u' returns address of y in memory
    'o' prints to octal value of the address
    When using the integer conversion specifiers you should dereference the pointer and use the proper
    specifier for the value
    When you want to show the address you should use %p and reference the pointer
    */
}




