/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void)

{
    char ch , file_name[200], *temp;
    FILE *fp, *fn;

    printf("The contents of words file are:\n");
    fp = fopen("words", "r");
    fn = fopen("lastword", "w");
    
    while((fgets(file_name, 25, fp)) != NULL) {
        printf("%s", file_name);
    }
    
    char delimit[]=" .,?!";
    char *p = strtok(file_name, delimit);
    
    while (p != NULL) {
        temp = p;
        p = strtok(NULL, delimit);
    }
    fprintf(fn, "%s\n", temp);
    
    fclose(fp);
    fclose(fn);
}