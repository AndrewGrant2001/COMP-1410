#include <stdio.h>
#include <string.h>

// Number of lines in the input text
#define SIZE 4

// Maximum word length (frequency of words with length 10 or more will be stored in one element
#define LENGTH 10

// Prototype of the function that will print out the array of char pointers (String), line by line
void printText(char *lines[]);

int main(void) {
    // The text content is stored in an array of pointers to characters (String)
    char *lines[SIZE] = {"Hello dear. My name is c. What is your name?",
                            "This is a test to check your capability programming in C.",
                            "Please try to write a C program to find frequency of the words by length in a text.",
                            "Then, try it on this text. Good luck!"};
    
    // Declaration and initialization of the array wordLength, to keep the word's lengths
    int wordLength[LENGTH] = {0};
    
    // Print out the text by calling printText function
    printText(lines);
    
    // Declaration of a one dimensional array of characters, called line
    // You can figure out the length of the array from variable lines above, and using strlen function
    int lineSize = 0;
    
    for (int i = 0; i < SIZE; ++i) {
        lineSize += strlen(lines[i]);
    }
    char line[lineSize + 1];
    
    // Store the text from the array lines to array line using strcpy and strcat
    strcpy(line, "");
    
    for (int i = 0; i < SIZE; ++i) {
        strcat(line, lines[i]);
    }
    
    // Start tokenizing the array line using delimiters space, period, comma, question mark, and exclamation mark.
    char delimit[]=" .,?!";
    char *p = strtok(line, delimit);
    
    // In a while loop, for each token, which is actually a word:
	//		Check the length of the token
	// 		Update the corresponding element of the array wordLength depending on the length of the token
	//		*Note: If the length of the token is equal or greater than LENGTH, you should update the last element of the array wordLength
	//		Then get the next token
	// Until there is no more token
    int len;
    while (p != NULL) {
        len = strlen(p);
        
        if (len > LENGTH) {
            ++wordLength[LENGTH - 1];
        }
        else {
            ++wordLength[len - 1];
        }
        p = strtok(NULL, delimit);
    }
    
    // Print out the word frequency table
    printf("\nLength\tFrequency\n");
    for (int i = 0; i < LENGTH; ++i) {
        printf("%d:\t%d\n", i + 1, wordLength[i]);
    }
}

void printText(char *lines[]) {
    puts("The text is:");
    puts("============");

    // Print out the text, line by line, using a for loop
    for (int i = 0; i < SIZE; ++i) {
    
        printf("%s\n", lines[i]);
    }
    
    puts("=======================");
}
