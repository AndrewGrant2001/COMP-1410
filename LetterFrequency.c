#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Number of lines in the input text
#define SIZE 4

// Prototype of the function that will print out the array of char pointers (String), line by line
void printText(char *lines[]);

int main(void) {

        // The text content is stored in an array of pointers to characters (String)
        char *lines[SIZE] = {"Hello dear. My name is c. What is your name?",
                                                 "This is a test to check your capability programming in C.",
                                                 "Please try to write a C program to extract frequency of the letters in a text.",
                                                 "Then, try it on this text. Good luck!"};

        // Declaration and initialization of an array to store the letter frequency (Consider letters as no case-sensitive)
        int frequency[26] = {0};

        // Print out the text by calling printText function
        printText(lines);   

        // Declaration of a one dimensional array of characters, called line
        // You can figure out the length of the array from variable lines above, and using strlen function
        int s=0,i;  //s is to sum the total length of all lines
        for(i=0;i<SIZE;i++)
            s += strlen(lines[i]);
        char line[s+1]; //In s+1 length the +1 is for null character

        // Store the text from the array lines to array line using strcpy and strcat
        for(i=0;i<SIZE;i++) //for each line
        {
            if(i==0)
                strcpy(line, lines[i]); //copying the first line to line array
            else
                strcat(line, lines[i]); //concatenating or appending the rest of the lines to the line array
        }
        
        // Start tokenizing the array line using delimiters space, period, comma, question mark, and exclamation mark.
        char delimit[]=" .,?!"; 
        char *p= strtok(line, delimit); 
        while(p!=NULL) {

        // In a while loop, for each token, which is actually a word:
        //Get every character of the token, capitalize it, and update the frequency of the letters
        //Then get the next token
        //Until there is no more token
            int i=0;    
            while(p[i]!='\0' && p[i]!=' ' && p[i]!='.' && p[i]!='?' && p[i]!='!')   
            {
                frequency[toupper(p[i])-'A']++; 
                i++; 
            }

            p = strtok(NULL, delimit);  
        }
        // ^^^^^^^^^^^^^^^^^^

        // COMPLETE THIS PART
        // ******************
        // Print out frequency of the letters
        puts("Letter Frequency"); //printing letter Frequency Table
        puts("================");
        for(i=0;i<26;i++)
            printf("%c: %d\n", i+65, frequency[i]); //printing frequency for each character from 'A' to 'Z'
        puts("================");
        
        // ^^^^^^^^^^^^^^^^^^

}

void printText(char *lines[]) {

        puts("The text is:");
        puts("============");

        // COMPLETE THIS PART
        // ******************
        // Print out the text, line by line, using a for loop
        int i;
        for(i=0;i<SIZE;i++) //printing each line to the screen
            printf("%s\n",lines[i]);
            
        // ^^^^^^^^^^^^^^^^^^

        puts("=======================");
}
