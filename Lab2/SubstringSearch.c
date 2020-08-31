/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char *searchPtr;
    char sentence[80];
    char word[15];
    
    printf("Enter a line of text: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    printf("Enter search string: ");
    scanf("%s", word);
    
    searchPtr = strstr(sentence, word);
    
    if(searchPtr){
        printf("%s", searchPtr);
        
        do { 
            int counter = 1;
            
            searchPtr = strstr(searchPtr + counter, word);
            
            if (searchPtr != NULL){
               printf("%s", searchPtr); 
            }
            else
                break;
        }while(1);
        
    }
    else{
        printf("Search String Wasn't Found! :(\n");
    }
    
}

