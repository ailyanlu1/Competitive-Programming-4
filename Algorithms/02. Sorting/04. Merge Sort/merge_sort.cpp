#include<stdio.h>
using namespace std;

/* function::Merge(array, start index, mid index, end index) */
void Merge (int a[], int start, int mid, int end) {
	// Set limit of temporary array
	int limX = mid-start+1, limY = end-mid;
	int x[limX], y[limY];
	
	// Read values in temporary array x
	for(int i=0; i<limX; i++)
		x[i] = a[i+start];
	
	// Read values in temporary array y
	for(int i=0; i<limY; i++)
		y[i] = a[i+mid+1];
	
	// Until one of the array is copied, insert values from both of the array that has the least current index value
	int i=0, j=0, k=start;
	while (i<limX && j<limY) {
		// If temporary array x has smaller value than array y then insert value in array x to our original array, else vice versa
		if (x[i] < y[j]) {
			a[k] = x[i];
			i++; 
		} else {
			a[k] = y[j];
			j++;
		}
		
		k++;
	}
	
	// Check if all the values in array x have been copied to original array
	while(i < limX) {
		a[k] = x[i];
		i++;
		k++;
	}
	
	// Check if all the values in array y have been copied to original array
	while(j < limY) {
		a[k] = y[j];
		j++;
		k++;
	}
} // #EndOfMerge

/* function::MergeSort(array, start index, end index) */
void MergeSort (int a[], int start, int end) {
	if (start < end) {
		// Find mid point of array
		int mid = start + (end - start)/2;
		
		// Apply merge sort to the partitions
		MergeSort(a, start, mid);
		MergeSort(a, mid+1, end);
		
		// Apply Merge sort algorithm
		Merge(a, start, mid, end);
	}
} // #EndOfMergeSort!

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
		
	// Merge sort function call
	MergeSort(a, 0, n-1);
	
	// Printing values after applying selection sort algorithm
	printf("After Sorting\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
