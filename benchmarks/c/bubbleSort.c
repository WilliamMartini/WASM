
// C program for implementation of Bubble sort
#include <stdio.h>
#include <stdlib.h>
#define N 1000000
#define R 100000000

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

// Driver program to test above functions
int main()
{
	srand(123);
    int arr[N];
    int i=0; 
    while(i < N) {
	    arr[i] = rand()%100000000; 
        i++;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    return 0;
}

