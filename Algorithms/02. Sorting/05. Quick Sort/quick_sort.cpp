#include<stdio.h>
using namespace std;

/* function Swap(value 1, value 2) */
int Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;	
} // #EndOfSwap!

/* function::Partition(array, start index, end index) */
int Partition (int a[], int start, int end) {
	// Set the pivot as last element
	int i = start-1;
	int pivot = a[end];
	
	// Iterate over the array
	for (int j=start; j<=end-1; j++) {
		// If value is less than the pivot then swap the pivot and the value and decrement the final swap index
		if (a[j] <= pivot) {
			i++;
			Swap(&a[i], &a[j]);
		}
	}
	
	// Final swap before returning new pivot
	Swap(&a[i+1], &a[end]);
	return i+1;
} // #EndOfPartition!

/* function::QuickSort(array, start index, end index) */
void QuickSort (int a[], int start, int end) {
	if (start < end) {
		int pivot = Partition(a, start, end);
		
		QuickSort(a, start, pivot-1);
		QuickSort(a, pivot+1, end);
	}
} // #EndOfQuickSort!

/* function::main() */
int main ( ) {
	// Making file stream as input stream
	freopen("input.txt", "r", stdin);
	
	// Reading number of elements in an array to sort
	int n;
	scanf("%d", &n);
	
	// Reading array and printing values before sorting them
	int a[n];
	printf("Before Sorting\n");
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		printf("%d ", a[i]);
	} printf("\n\n");
		
	// Quick sort function call
	QuickSort(a, 0, n-1);
	
	// Printing values after applying selection sort algorithm
	printf("After Sorting\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
