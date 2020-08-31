/****************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char *fDigit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};//first digit array
char *sDigit[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", //second digit array
                  "seventeen", "eighteen", "nineteen"};
char *tDigit[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                  "sixty", "seventy", "eighty", "ninety"};//third digit array
char *foDigit[] = {"hundred", "thousand"};//larger number array

void convert(char *num);//declaring convert function

int main()
{
    //declaring varibles for use
    char input[4] = {'\0'};
    int check;
    
    //do loop to get input in certain range
    do {
        printf("Enter integer number (0 - 9999): ");
        scanf("%s", input);
        sscanf(input, "%d", &check);
    }while(check < 0 || check > 9999);
    
    convert(input);//calling convert function
}

//function to convert input into string text of number
void convert(char *num){
    int len = strlen(num);//finding how many digits number is
    
    //if statement for one digit numbers
    if (len == 1) { 
        printf("%s\n", fDigit[*num - '0']); 
        return; 
    } 
  
    // Iterate while num is not empty string
    while (*num != '\0') { 
        // Code path for first 2 digits
        if (len >= 3) { 
            if (*num -'0' != 0) { 
                printf("%s ", fDigit[*num - '0']); 
                printf("%s ", foDigit[len-3]); // here len can be 3 or 4 
            } 
            --len; 
        } 
        else { 
            //if statements to correctly find proper digits and creating string
            if (*num == '1') { 
                int sum = *num - '0' + *(num + 1)- '0'; 
                printf("%s\n", sDigit[sum]); 
                return; 
            } 
            else if (*num == '2' && *(num + 1) == '0') { 
                printf("twenty\n"); //Handle 20
                return; 
            } 
            else { 
                int i = *num - '0'; 
                printf("%s ", i? tDigit[i]: ""); 
                ++num; 
                if (*num != '0') 
                    printf("%s ", fDigit[*num - '0']); 
            } 
        } 
        ++num;//increment
    } 
} 

