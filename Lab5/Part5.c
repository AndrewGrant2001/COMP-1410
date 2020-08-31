/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX 20

char str[MAX], stack[MAX];

int top = -1;

char pop(){
    return stack[top--];
}

void push(char ch){
    stack[++top] = ch;
}

void postfix_to_infix(char expression[]){
    int count, length;
    char element, operate;
    length = strlen(expression);

    for(count = 0; count < MAX; count++){
        stack[count] = 0;
    }
    
    printf("Infix Expression: ");
    printf("%c", expression[0]);
    
    for(count = 1; count < length; count++){
        if(expression[count] == '-' || expression[count] == '/' || 
                        expression[count] == '*'|| expression[count] == '+'){
            element = pop();
            operate = expression[count];
            printf(" %c %c", operate, element);
        }
        else{
            push(expression[count]);
        }
    }
    printf("%c", expression[top--]);
}

int main(){
    char postfix_expression[50];

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix_expression);
    
    postfix_to_infix(postfix_expression);
    puts("");
}



