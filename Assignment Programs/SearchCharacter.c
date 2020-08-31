/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //declaring variables and array
    char text[80] = {'\0'};
    char letter;
    int counter = 0;
    
    //prompt for test
    printf("Enter text: ");
    fgets(text, 80, stdin);
    
    //prompt for search character
    printf("Enter search character: ");
    scanf("%c", &letter);
    
    //loop to calculate how many times the character occurs not case sensitive
    for(int i = 0; text[i] != '\0'; i++){
        if(tolower(text[i]) == tolower(letter)){
            counter++;
        }
    }
    
    printf("The letter '%c' occurs %d times.", toupper(letter), counter);//output
    
    
    
}


