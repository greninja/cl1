#include<stdio.h>
#include<omp.h>
#include<ctime>
#include<iostream>

using namespace std;
// A utility function to swap two elements

void swap(int* a, int* b)

{

    int t = *a;

    *a = *b;

    *b = t;

}

 

/* This function takes last element as pivot, places

   the pivot element at its correct position in sorted

    array, and places all smaller (smaller than pivot)

   to left of pivot and all greater elements to right

   of pivot */

int partition (int arr[], int low, int high)

{

    int pivot = arr[high];    // pivot

    int i = low;  // Index of smaller element

 

    for (int j = low; j <= high- 1; j++)

    {

        // If current element is smaller than or

        // equal to pivot

        if (arr[j] <= pivot)

        {

           
            swap(&arr[i], &arr[j]);
			i++;    // increment index of smaller element

        }

    }

    swap(&arr[i], &arr[high]);

    return i;

}

 

/* The main function that implements QuickSort

 arr[] --> Array to be sorted,

  low  --> Starting index,

  high  --> Ending index */

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now

           at right place */

	#pragma omp parallel sections
	{
        int pi = partition(arr, low, high);
        // Separately sort elements before

        // partition and after partition

	#pragma omp section
	{
        quickSort(arr, low, pi - 1);
	}
	#pragma omp section
	{
        quickSort(arr, pi + 1, high);
	}
    	
	}
}
}


/* Function to print an array */

void printArray(int arr[], int size)

{

    int i;

    for (i=0; i < size; i++)

        printf("%d ", arr[i]);
}

 

// Driver program to test above functions

int main()

{

    int arr[] = {1,2,3,4,5,6};

    int n = sizeof(arr)/sizeof(arr[0]);

    int start_time = clock();
    quickSort(arr, 0, n-1);
	int end_time = clock();
	printf("Sorted array:");
	printArray(arr, n);
	cout << "Time for execution" << (end_time - start_time)/double(CLOCKS_PER_SEC) * 1000 << endl;
    return 0;

}

