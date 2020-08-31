/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 8

int main()
{
    char word[SIZE] = {'\0'};
    int counter = 0;
    
    puts("** Duck Duck Goose Game **\n******** Have Fun! *******");
    
    do {
        do{
            puts("Enter word 'duck' or 'goose':");
            fgets(word, SIZE, stdin);
            for (int i = 0; word[i]!='\0'; i++) {
                if(word[i] >= 'A' && word[i] <= 'Z') {
                    word[i] = word[i] + 32;
                }
            }
        } while(strncmp(word,"duck",4) && strncmp(word,"goose",5));
        
        if(!strncmp(word,"duck",4)){
            counter++;
        }
        else{
            printf("%d times duck was inputted!", counter);
            break;
        }
    } while(1);
    
}

