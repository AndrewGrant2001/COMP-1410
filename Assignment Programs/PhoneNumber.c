/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //declaring and inializing variables
    char phoneNumber[600], area[4] = {0}, number[9] = {0}, *p;
    int areaCode;
    long numberCode;
    
    //prompt for phone number from user
    printf("Enter a phone number (ex. (555) 555-5555): ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    
    p = strtok(phoneNumber, "()- ");//creating a token
    
    //if statement, if true, concatenates the terms
    if (p != NULL) {
        strncat(area, p, sizeof(area - 1));
    }
    
    p = strtok(NULL, "()- ");//creating a token
    
    //if statement, if true, concatenates the terms
    if (p != NULL){
        strncat(number, p, sizeof(number - 1));
    }
    
    p = strtok(NULL, "()- ");//creating a token
    
    //if statement, if true, concatenates the terms
    if (p != NULL) {
        strncat(number, p, sizeof(number - 1));
    }
    
    sscanf(area, "%d", &areaCode);//taking area array and converting to integer
    sscanf(number, "%ld", &numberCode);//taking number array and converting to long integer
    
    //outputting the numbers
    printf("%d%ld\n", areaCode, numberCode);
}


