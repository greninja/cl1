#include<stdio.h>
#include<omp.h>
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
    int i = (low);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
                // increment index of smaller element
            swap(&arr[i], &arr[j]);
			i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return (i);
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
    int arr[] = {-10, 7, 8, 9, -111, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array:");
    printArray(arr, n);
    return 0;
}

