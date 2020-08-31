/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// A function to bubble sort 
void bubbleSort(int arr[], int n);
  
// Driver program to test above functions 
int main() { 
    int arr[200] = {}; //array declaration
    int counter = 0;
    
    do {
        printf("Enter number for array (0 to stop adding values):\n");
        scanf("%d", &arr[counter]);
        
        if (arr[counter] == 0){
            break;
        }
        
        counter++;
    }while(1);
    
    int n = sizeof(arr)/sizeof(arr[0]); //determining the size of array
    
    bubbleSort(arr, n); //function to sort elements
    
    //output
    printf("Sorted array : \n");
    for (int i=0; i < n; i++) {
        if (arr[i] != 0){
            printf("%d ", arr[i]);   
        }
    }
    puts("");
}

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) { 
    //if array is size 1
    if (n == 1){ 
        return; 
    }
  
    //for loop to move largest value to the end (right)
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) {
            arr[i] = arr[i] ^ arr[i+1];
            arr[i+1] = arr[i] ^ arr[i+1];
            arr[i] = arr[i] ^ arr[i+1];
        }
    }
    return bubbleSort(arr, n-1);//recursive part
} 

