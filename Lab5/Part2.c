/******************************************************************************
Name: Andrew Grant
Course: COMP-1410 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *f1;
   FILE *f2;

   f1 = fopen("f1", "r");
   f2 = fopen("f2", "r");

   if(f1 == NULL)
   {
       printf("The f1.txt file cannot be opened!\n");
       exit(EXIT_FAILURE);
   }
   if(f2 == NULL)
   {
       printf("The f2.txt file cannot be opened!\n");
       exit(EXIT_FAILURE);
   }

   int a, b, fmax;

   fscanf(f1, "%d", &a);
   fscanf(f2, "%d", &b);

   if (a > b)
       fmax = a;
   else
       fmax = b;

   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("fmax = %d\n\n", fmax);

   fclose(f1);
   fclose(f2);
}