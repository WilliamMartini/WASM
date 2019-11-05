/*This program multiplies two randomly generate matricies of size N,N
* We can set N using: ./a.out 42
*/
#include <stdio.h>
#include <stdlib.h>
int N = 800;
#define R 100

// This function multiplies mat1[][] and mat2[][], 
// and stores the result in res[][] 
void multiply(double **mat1, double **mat2, double **res) { 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++){  
      res[i][j] = 0;
			for (int k = 0; k < N; k++) 
				res[i][j] += mat1[i][k]*mat2[k][j]; 
    }
} 

double** allocate_2D(int rows, int cols){
  double  **mat;
  mat = calloc(rows, sizeof(double *));
  for(int i = 0; i < rows; i++)
     mat[i] = calloc(cols, sizeof(double));
  return mat;
}

void free_2D(double **mat, int rows){
  for(int i = 0; i < rows; i++)
    free(mat[i]);
  free(mat);
}

int main(int argc, char **argv) {
  if(argc == 2)
    N = atoi(argv[1]);
	
  srand(123);
  double  **mat1, **mat2, **res;
  mat1 = allocate_2D(N,N);
  mat2 = allocate_2D(N,N);
  res = allocate_2D(N,N);

  for(int i = 0; i<N; i++){
    for(int j = 0; j<N; j++){
      mat1[i][j] = rand()%R + rand()%R/(double)R;
      mat2[i][j] = rand()%R + rand()%R/(double)R;
    }
  }

	multiply(mat1, mat2, res); 
  free_2D(mat1,N);
  free_2D(mat2,N);
  free_2D(res,N);
	return 0; 
} 
