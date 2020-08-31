/******************************************************************************
Name: Andrew Grant
*******************************************************************************/

#include<stdio.h>

void display(unsigned val);

unsigned calPower(unsigned number, unsigned power);

int main() {
    unsigned num, ans, power;//declaring variables

    //prompt for number
    printf("Enter a number: ");
    scanf("%u", & num);

    //prompt for power
    printf("Enter a power: ");
    scanf("%u", & power);

    //Perform the shifting.
    ans = calPower(num, power);

    //Display the result in integer.
    printf("The integer result is: %u\n", ans);

    //Display the result in bits.
    printf("The result in bits is : \n");

    display(ans);//function outputs the number in bits
}

//function to calculate integer result
unsigned calPower(unsigned n, unsigned p) {
    return n << p;
}

//function to output number in bits
void display(unsigned val) {
    unsigned c, mask = 1 << 31;

    printf("%u = ", val); //outputing purposes

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

