/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void sum(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);

void (*n[4]) (double x, double y) = {sum, subtract, multiply, divide};


int main()
{
    puts("```````Calculator Menu````````");
    puts("```0 - Add two numbers````````");
    puts("```1 - Subtract two numbers```");
    puts("```2 - Multiply two numbers```");
    puts("```3 - Divide two numbers`````");
    
    int choice;
    double num1, num2;
    
    do {
        do {
            printf("Enter your menu selection (4 to exit): ");
            scanf("%d", &choice);
        } while(choice < 0 || choice > 4);
        
        if (choice == 4){
            puts("Goodbye");
            break;
        }
        
        printf("Enter a number: ");
        scanf("%lf", &num1);
        
        printf("Enter another number: ");
        scanf("%lf", &num2);
        
        if (choice == 3 && num2 == 0){
            do {
                printf("Enter valid number!\n");
                printf("Enter another number: ");
                scanf("%lf", &num2);
            } while(num2 == 0);
        }
        
        (*n[choice])(num1, num2);
    } while(1);
}

void sum(double a, double b){
    printf("Adding %.2lf and %.2lf\n", a, b);
    printf("The answer is %.2lf\n", a + b);
}

void subtract(double a, double b){
    printf("Subtracting %.2lf by %.2lf\n", a, b);
    printf("The answer is %.2lf\n", a - b);
}

void multiply(double a, double b){
    printf("Multiplying %.2lf by %.2lf\n", a, b);
    printf("The answer is %.2lf\n", a * b);
}

void divide(double a, double b){
    printf("Dividing %.2lf by %.2lf\n", a, b);
    printf("The answer is %.2lf\n", a / b);
}

