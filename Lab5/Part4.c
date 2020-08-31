#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *resPtr;
    resPtr=fopen("datasize.dat","w");

    fprintf(resPtr,"%s%16s\n%s\n", "Data type", "Size", "-------------------------");
    printf("%s%16s\n%s\n","Data type","Size", "-------------------------");

    fprintf(resPtr,"%s%21lu\n","char", sizeof(char));
    printf("%s%21lu\n","char", sizeof(char));

    fprintf(resPtr,"%s%12lu\n","unsigned char", sizeof(unsigned char));
    printf("%s%12lu\n","unsigned char", sizeof(unsigned char));

    fprintf(resPtr,"%s%16lu\n","short int",sizeof(short int));
    printf("%s%16lu\n","short int",sizeof(short int));

    fprintf(resPtr,"%s%7lu\n","unsigned short int",sizeof(unsigned short int));
    printf("%s%7lu\n","unsigned short int",sizeof(unsigned short int));


    fprintf(resPtr,"%s%22lu\n","int",sizeof(int));
    printf("%s%22lu\n","int",sizeof(int));

    fprintf(resPtr,"%s%13lu\n","unsigned int",sizeof(unsigned int));
    printf("%s%13lu\n","unsigned int",sizeof(unsigned int));

    fprintf(resPtr,"%s%8lu\n","unsigned long int",sizeof(unsigned long int));
    printf("%s%8lu\n","unsigned long int",sizeof(unsigned long int));

    fprintf(resPtr,"%s%20lu\n","float",sizeof(float));
    printf("%s%20lu\n","float",sizeof(float));

    fprintf(resPtr,"%s%19lu\n","double",sizeof(double));
    printf("%s%19lu\n","double",sizeof(double));

    fprintf(resPtr,"%s%14lu\n","long double",sizeof(long double));
    printf("%s%14lu\n","long double",sizeof(long double));

    fclose(resPtr);
    return 0;
}