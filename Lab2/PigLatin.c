/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>
#include <string.h>

//function to translate to pig latin and print
void printLatinWord(char a[]);

int main()
{
    char str[80] = {'\0'};//creating array of characters size 80
    
    //prompts
    printf("Enter English sentence: \n");
    fgets(str, 80, stdin);
    
    char *tokenPtr = strtok(str, " ");//starting the first token
    
    //while loop until phrase is finished
    while (tokenPtr != NULL){
        
        printLatinWord(tokenPtr);//calling function
        
        tokenPtr = strtok(NULL, " ");//creating next token
    }
    puts("");//output purposes
}

void printLatinWord(char a[])
{
    //for loop to print characters from 2 letter to end of word
    for (int i = 1; i < strlen(a); i++) {
        //if statement to ignore enter character at end of string
        if (!(a[i] == '\n')){
            printf ("%c", a[i]);//print character
        }
    }
    printf("%cay ", a[0]);//printing first character at end and adding ay
}
