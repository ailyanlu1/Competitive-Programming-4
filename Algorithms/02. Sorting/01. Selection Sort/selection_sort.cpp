#include<stdio.h>
using namespace std;

/* function::SelectionSort(array, size) */
void SelectionSort (int a[], int n) {
	for(int i=0; i<n-1; i++) {
		// Set the starting index as min_index
		int min_index = i;
		
		// Iterate throught the unsorted array and find the minimum element
		for(int j=i+1; j<n; j++) {
			if (a[min_index] > a[j])
				min_index = j;
		}
		
		// Swap the min_index value and current position to set value to its appropriate position
		int tmp = a[min_index];
		a[min_index] = a[i];
		a[i] = tmp;
	}
} // #EndOfSelectionSortAlgorithm!

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
		
	// Selection sort function call
	SelectionSort(a, n);
	
	// Printing values after applying selection sort algorithm
	printf("After Sorting\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
