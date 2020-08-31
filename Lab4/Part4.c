/******************************************************************************
Name: Andrew Grant
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

unsigned reverseBits(unsigned val);
void display(unsigned val);

int main()
{
    unsigned num;//declaring variable
    
    //prompt to get integer from user
    printf("Enter an integer: ");
    scanf("%u",&num);
    
    //output the integer in bits
    printf("Original integer in bits:\n");
    display(num);

    //output and function called to output reverse order
    printf("Integer after reversing order of bits:\n");
    display(reverseBits(num));
}

//function to reverse the order of bits
unsigned reverseBits(unsigned val)
{
    unsigned mask=1, temp=0;
    
    //loop to start converting to other bit output
    for(int i=0; i<=31; i++)
    {
        temp<<=1;
        temp|=(val & mask);
        val>>=1;
    }
    return temp;//return the value of reverse order
}
void display(unsigned val)
{
    unsigned c, mask = 1 << 31;

    //loop to output the bits number
    for (c = 1; c <= 32; c++) {
        val & mask ? putchar('1') : putchar('0');
        val <<= 1;

        //outputing purposes
        if (c % 8 == 0) {
            putchar(' ');
        }

    }
    putchar('\n'); //outputing purposes
}


