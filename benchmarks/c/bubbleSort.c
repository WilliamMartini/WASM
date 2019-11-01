// C program for implementation of Bubble sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define R 1000

typedef unsigned int uint;
typedef unsigned long ulong;

const ulong N[9] = {10000,20000,30000,40000,50000,60000,70000,80000,90000};

void swap(uint *xp, uint *yp)
{
    uint temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(uint *arr, ulong n)
{
   ulong i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

// Driver program to test above functions
int main()
{
	int max_n = (sizeof(N)/sizeof(N[0]))-1;
	srand(123);
    uint *arr;
    arr = malloc((N[max_n])*sizeof(uint));
    ulong i=0; 

    while(i < N[max_n]) {
	    arr[i] = rand()%R; 
        i++;
    }
    
    clock_t t;
    ulong k=0;
    while(k <= max_n){
        t = clock();
        bubbleSort(arr, N[k]);
        t = clock() - t; 
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    
        printf("N(%lu): %f seconds \n",N[k], time_taken);
        k++;
    }
    free(arr);
    return 0;
}