/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>

//function to check if number is prime recursively
int prime(int num, int a);

int main()
{
    int number, result;//creating varaibles
    
    //prompt for integer number
    printf("Enter integer number: ");
    scanf("%d", &number);
    
    //if statement to catch for 0 and 1
    if(number == 1 || number == 0) {
        printf("%d is not a prime number!", number);//output
    }
    else {
        result = prime(number, number/2);//function to check if prime
        
        //if statement for outputting
        if(result) {
            printf("%d is a prime number!", number);//output
        }
        else {
            printf("%d is not a prime number!", number);//output
        }
    }
    
    
}

//function to check if number is prime recursively
int prime(int num, int a){
    //if statements to return proper answers
    if(a == 1) {
        return 1;
    }
    else {
        if(num % a == 0) {
            return 0;
        }
        else {
            return prime(num, a - 1);
        }
    }
}
