// C program to multiply two square matrices. 
#include <stdio.h>
#include <stdlib.h>
#define N 800
#define R 100

// This function multiplies mat1[][] and mat2[][], 
// and stores the result in res[][] 
void multiply(int mat1[][N], int mat2[][N], int res[][N]) 
{ 
	int i, j, k; 
	for (i = 0; i < N; i++) 
	{ 
		for (j = 0; j < N; j++) 
		{ 
			res[i][j] = 0; 
			for (k = 0; k < N; k++) 
				res[i][j] += mat1[i][k]*mat2[k][j]; 
		} 
	} 
} 

int main() 
{ 
	srand(123);
	int mat1[N][N];
	int i, o;
    for(o = 0; o<N; o++){
        for(i = 0; i<N; i++){
            mat1[o][i] = rand()%R;
        }
    }
  
    int mat2[N][N];
	
  	int n,m;
    for(n = 0; n<N; n++){
        for(m = 0; m<N; m++){
            mat2[n][m] = rand()%R;
        }
    }
	int res[N][N]; // To store result 
	int k, j; 
	multiply(mat1, mat2, res); 

	return 0; 
} 