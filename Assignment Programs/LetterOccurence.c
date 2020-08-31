/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

int main() {
    int alphabet[26] = {0};//creating array to store occurence of each letter
    char sentence[SIZE], c;//declaring varibles for use

    //prompt to enter text
    printf("Enter lines of text: ");
    fgets(sentence, SIZE, stdin);

    //for loop to count each character
    for (int j = 0; sentence[j] != '\0'; j++) {
        c = tolower(sentence[j]);
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a']++;
        }
    }
    puts("");//output
    
    int counter = 0;

    //loop to output table of letters and frequency
    for (int i = 0; i < 26; i++) {
        counter++;
        printf("%c/%c: %d", ('A' + i), ('a' + i), alphabet[i]);
        if('a' + i == 'z'){
            puts(" |");
        }
        else if(counter % 4 != 0){
            printf(" | ");
        }
        else if (counter % 4 == 0){
            puts("");
            printf("-------+--------+--------+-------\n");
        }
    }
    puts("");
}

