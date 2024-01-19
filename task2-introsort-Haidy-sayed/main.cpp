#include <bits/stdc++.h>
using namespace std;
#include<stdio.h>

//Creating a random arr with size " "
#define m 20
int arr[m];
int quickArray[m];
int introArray[m];
int* Qptr;
int* Iptr;
void rand_arr(int arr [], int size){
	for(int i=0; i<(size-1);i++){
		arr[i]=rand();
	}
}
/*Implementing Quick Sort*/
int quick_partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			int temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp2=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp2;
	
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = quick_partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* End of Quick Sort implementation */

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/*Start of Intro Sort*/
//Insertion Sort 
void insertionSort(int arr[]){
	int i, key, j;
    for (i = 1; i < m; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Heap Sort
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
    	int temp = arr[i];
    	arr[i]=arr[largest];
    	arr[largest]=temp;
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
    	arr[0]=arr[i];
    	arr[i]=temp;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
// Function to perform introsort on the given array
int* introsort(int a[], int begin, int end, int maxdepth)
{
    // perform insertion sort if partition size is 16 or smaller
    if ((end - begin) < 16) {
        insertionSort(a);
    }
    // perform heapsort if the maximum depth is 0
    else if (maxdepth == 0) {
        heapSort(a , (end-begin-1));
    }
    else {
        // otherwise, perform Quicksort
        quickSort(a,begin,end);
    }
    return a;
}

int main(){
	rand_arr(arr, m);
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Original array: \n");
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	printf("quickSort array: \n");
	printArray(arr, n);
	// get the maximum depth
    int maxdepth = log(n) * 2;
    // sort the array using introsort the algorithm
    introsort(arr, 0, n-1, maxdepth);
    printf("IntroSorted: \n");
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	
	
	return 0;
}
