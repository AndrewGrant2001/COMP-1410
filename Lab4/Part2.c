/******************************************************************************
Name: Andrew Grant
*******************************************************************************/

#include <stdio.h>

union myUnion {
    char c;
    short s;
    int i;
    long l;
};

int main() {
    union myUnion a;
    
    printf("Please enter a character: ");
    scanf("%c", &(a.c));
    printf("As a character: %c\n", a.c);
    
    printf("Please enter a short: ");
    scanf("%hd", &(a.s));
    printf("As a short: %hd\n", a.s);
    
    printf("Please enter an int: ");
    scanf("%d", &(a.i));
    printf("As an int: %d\n", a.i);
    
    printf("Please enter a long: ");
    scanf("%ld", &(a.l));
    printf("As a long: %ld\n\n", a.l);
}


