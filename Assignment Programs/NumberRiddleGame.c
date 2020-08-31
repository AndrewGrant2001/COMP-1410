/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
Assignment 1 - Version 1
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int row, col;//creating global variables for row size and column size

//Show the board on the screen
void printTable(int array[row][col], int rows, int cols);

//Randomly populate the array except the last element
void fillArray(int arr[row][col], int r, int c);

//Generate a random number between min and max, inclusive.
int MyRand(int min, int max);

//Check if an element exists in the array already (Makes it unique)
int Dexists(int a[row][col], int num, int x, int y);

//Check if the move is valid or not
int valid(int n1, int n2, int d1, int d2);

//function to swap two elements in the array
int swapPOS(int sArray[row][col], int a1, int a2, int a3, int a4);

int main()
{
    //outputing purposes
    puts("**************************");
	puts("******* Welcome to *******");
	puts("*** Number Riddle Game ***");
	puts("****** Andrew Grant ******");
	puts("**************************");

	srand(time(NULL));//creating a seed for random number

    //do loop to run until player wants to quit
	do {
		//Getting the number of rows from the user
		do {
			printf("Enter number of rows (3 - 8):\n");
			scanf("%d",&row);
		} while (row <3 || row > 8);

        //Getting the number of columns from the user
		do {
			printf("Enter number of columns (3 - 8):\n");
			scanf("%d",&col);
		} while (col < 3 || col > 8);
		
		int ag[row][col];//creating array
		
		//loops to intialize array to 0
		for (int i = 0; i < row; i++){
		    for (int j = 0; j < col; j++){
		        ag[i][j] = 0;
		    }
		}
		
		fillArray(ag, row, col);//Function to populate array with random numbers in a range
		
		//Creating a random empty cell in the table
		int g = rand() % (row - 1);
		int h = rand() % (col - 1);
		int emptrow = g;
		int emptcol = h;
		ag[row - 1][col - 1] = ag[g][h];
		ag[g][h] = 0;
		
		printTable(ag, row, col);//print table to show to user
		
		int won = 0;//intialize a variable to track if user has won

        //Starting the time
		time_t start, end;
		time(&start);
		
		int counter = 1;//creating a move counter
		
		//do loop to run until user has won or quits
		do {
		    int answer;//creating a variable for user to enter there move
		    
		    //do loop to run until valid input is entered
			do {
				printf("(#Move %d), Enter the number you want to move ( 0 to exit):\n", counter);//prompt
				scanf("%d", &answer);
				
				//checking if input is valid
				if (answer >= 0 && answer < row*col){
				    break;
				}
				else {
					printf("Invalid number.\n");
				}
			} while (1);
			
			//check if user wants to quit
			if (answer == 0) {
				break;
			}
	    
	        //for loops to run to make moves in the game
	        for (int i = 0; i < row; i++){
	            for(int u = 0; u < col; u++){
	                //to check if the answer is in the array at certain spot
	                if (ag[i][u] == answer){
	                    
	                    int validMove = valid(i, emptrow, u, emptcol);//check if move is valid
	                    
	                    //if statements to do proper tasks based on valid function return
    	                if(validMove == 1){
    	                    
    	                    swapPOS(ag, emptrow, emptcol, i, u);//function to swap positions

    	                    emptcol = u;//reset empty column
    	                    emptrow = i;//reset empty row
    	                    
    	                    printTable(ag, row, col);//output table
    	                    
    	                    int check = 0;//create variable to see how many spots are correct
    	                    int current = 1;//create variable to help see how many are correct
    	                    
    	                    //for loops to check how many numbers are in correct position
    	                    for(int i = 0; i < row; i++){
    	                        for(int j = 0; j < col; j++){
    	                            if (ag[i][j] == current){
    	                                check++;
    	                            }
    	                            current++;
    	                        }
    	                    }
    	                    
    	                    
    	                    //Game is over and the player wins, end time and output
    						if (check == row*col-1) {
    							time(&end);
    							double t = difftime(end,start);
    							printf("Excellent!!! you solved it with %d guesses, in %3.0f seconds.\n",counter, t);
    							won = 1;
    							goto Again;//exit all loops
    						}
    	                }
    	                else {
                            printf("This cell can't move!\n");
                        }
                        goto Continue;//breaks both loops to prevent errors
                    }
                }
	        } 
	        //using this to prevent errors
	        Continue:
	            continue;
		} while(!won); 
		
		//goto function to prompt in user wishes to play again
	    Again:
    	    // Ask the user to play again or not
    		printf("To play again, enter 1:\n");
    		int answer;
    		scanf("%d", &answer);
    		if (answer != 1) {
    			break;
    		}
	} while(1);
}

//Show the board on the screen
void printTable(int array[row][col], int rows, int cols){
    //for loops to print out the table in proper format
    for (int i = 0; i < row; i++){
	    for (int j = 0; j < col; j++){
	        if (array[i][j] == 0){
	            printf("   | ");
	        }
	        else {
	            printf("%2d | ", array[i][j]);
	        }
	    }
	    puts("");
	}
}

//Randomly populate the array except the last element
void fillArray(int arr[row][col], int r, int c){
    //loops to fill array with random numbers and to make them unique
    int size = r * c;
    for (int i = 0; i < r; i++){
        int j = 0;
        while (j < c){
            int temp = MyRand(1, size - 1);
            if (!Dexists(arr, temp, r, c)){
                arr[i][j] = temp;
                j++;
                
            }
            //if statement to prevent infinite loop
            if(i == (r-1) && j == (c - 1))
            {
                break; 
            }
        }
    }
}

//Generate a random number between min and max, inclusive.
int MyRand(int min, int max){
    //creating random numbers and return them
    int range = max-min+ 1;
	return rand() % range + min;
}

//Check if an element exists in the array already (Makes it unique)
int Dexists(int a[row][col], int num, int x, int y){
    //for loop to check if number already exists
    for (int i = 0; i < x; i++){
	    for (int j = 0; j < y; j++){
	        if (num == a[i][j]){
	            return 1;
	        }
	    }
	}
	return 0;
}

//Check if the move is valid or not
int valid(int n1, int n2, int d1, int d2){
    //if statement to check if spots are beside eachother in the array
    if(abs(n1 - n2) + abs(d1 - d2) == 1){
        return 1;
    }
    else{
        return 0;
    }
}

//function to swap two elements in the array
int swapPOS(int sArray[row][col], int a1, int a2, int a3, int a4){
    //using ^ operator to swap elements without temp variable
    sArray[a1][a2] = sArray[a1][a2] ^ sArray[a3][a4];
    sArray[a3][a4] = sArray[a1][a2] ^ sArray[a3][a4];
    sArray[a1][a2] = sArray[a1][a2] ^ sArray[a3][a4];
}

