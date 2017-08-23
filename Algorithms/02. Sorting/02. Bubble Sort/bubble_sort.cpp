#include<stdio.h>
using namespace std;

/* function::BubbleSort(array, size) */
void BubbleSort (int a[], int n) {
	for(int i=0; i<n-1; i++) {
		// Iterate for each remaining bubbles in the unsorted array
		for(int j=0; j<n-i-1; j++) {
			// Swap bubbles if condition meets
			if (a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
} // #EndOfBubbleSort!

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
		
	// Bubble sort function call
	BubbleSort(a, n);
	
	// Printing values after applying selection sort algorithm
	printf("After Sorting\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
