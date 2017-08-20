#include<stdio.h>
using namespace std;

/* function::InsertionSort(array, size) */
void InsertionSort (int a[], int n) {
	// from 1...Size of array
	for(int i=1; i<n; i++) {
		// Set the starting index and the value of that index
		int j = i-1;
		int key = a[i];
		
		// While the key is less than a[j], shift a[j] right
		while (j>=0 && a[j]>key) {
			a[j+1] = a[j];
			
			j--;
		}
		
		// Set the key to its appropriate position
		a[j+1] = key;
	}
} // #EndOfInsertionSort!

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
		
	// Insertion sort function call
	InsertionSort(a, n);
	
	// Printing values after applying selection sort algorithm
	printf("After Sorting\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
