/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>

//struct with name Emp, double, char, int array variables
struct Emp {
    double d;
    char *str;
    int arr[11];
};

int main() {
    Emp emp[30];
    
    emp[29].arr[10] = 12; //assigning 12 to the last element of emp and last element of arr
    
    emp[0].d = 3.5; //assigning 3.5 to the 0 element (first)
    
    int k = 15; //k can equal any number from 1 - 28
    
    emp[k].str = "Hello"; //assigning hello to element k in emp
}

