/******************************************************************************
Name:Andrew Grant
Course: COMP-1410
*******************************************************************************/
#include <stdio.h>

long fact (int a);

int main()
{
    int num;
    printf("Enter number to calculate factorial: ");
    scanf("%d", &num);
    printf("%ld\n", fact(num));
}

long fact (int a){
    if (a <= 1) {
        return 1;
    }
    else {
        return a * fact(a - 1);
    }
}





