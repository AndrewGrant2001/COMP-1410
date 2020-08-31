#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// A regular function to check and return the maximum value between two integers
int max(int a, int b);

// A recursive function for recursively find and return the maximum value in an array of integers
int maximumValue(int a[], int size);

int main(void) {

	srand(time(NULL));

	int myArray[SIZE];

	// populate the array with positive random integers less than 100
    for (int i = 0; i < SIZE; i++){
        myArray[i] = (rand() % 100); //number between 0 and 99
    }

	// Print out the elements of the array in one line
    for (int i = 0; i < SIZE; i++){
        printf("%d ", myArray[i]);
    }

    puts("");//output

	// Find and print out the maximum value in the array by calling the recursive function maximumValue
    printf("Max value is %d\n", maximumValue(myArray, SIZE));
}

int max(int a, int b) {
	// if a is greater than or equal to b, return a, otherwise return b
    if (a >= b)
        return a;
    else
        return b;
}

int maximumValue(int a[], int size) {
	// If there is only one element in the current array, return it.
    if (size == 1){
        return a[0];
    }
    else {
        //Call the max function with two parameters, the first element of the array and maximumValue of the rest of the array.
        return max(a[0], maximumValue(a + 1, size - 1));
    }
}
