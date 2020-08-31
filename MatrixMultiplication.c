#include <stdio.h>

#define SIZE 4

// The prototype of the function to compute matrix multiplication of matrices a and b, and put it into matrix c
// m: Number of rows in matrix a
// n: Number of columns in matrix a (and number of rows in matrix b)
// p: Number of columns in matrix b
void matrixMult(int m, int n, int p, int a[m][n], int b[n][p], int c[m][p]);

int main(void) {

	// Declaration of the variables to keep the matrices' dimensions
	// m: Number of rows in matrix a
	// n: Number of columns in matrix a (and number of rows in matrix b)
	// p: Number of columns in matrix b
	int m, n, p;

	// Get the number of rows and columns of matrix a, and number of columns of matrix b
	printf("Please enter the number of rows in matrix a: ");
	scanf("%d", &m);
	printf("Please enter the number of columns in matrix a: ");
	scanf("%d", &n);
	printf("Please enter the number of columns in matrix b: ");
	scanf("%d", &p);

	// Declaring three matrices, a, b, and c based on the rows and columns given above
    int a[m][n], b[n][p], c[m][p];

	// Populate matrix a by user entries
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Enter integer value for a(%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

	// Populate matrix b by user entries
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            printf("Enter integer value for b(%d, %d): ", i , j);
            scanf("%d", &b[i][j]);
        }
    }

	// Call function matrixMult to compute multiplication of a and b into c
    matrixMult(m, n, p, a, b, c);

	// Print out matrix c
	printf("The answer is: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            printf("%3d ", c[i][j]);
        }
        puts("");
    }
}

void matrixMult(int m, int n, int p, int a[m][n], int b[n][p], int c[m][p]) {
	//inializing array to 0;
    for(int i = 0; i < m; ++i){
		for(int j = 0; j < p; ++j){
			c[i][j] = 0;
		}
	}
	
    // Compute the multiplication of matrix a and matrix b and store the result into matrix c
    for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < p; j++)
		{
			for(int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

