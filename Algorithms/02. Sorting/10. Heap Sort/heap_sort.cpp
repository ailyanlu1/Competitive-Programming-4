#include<stdio.h>
using namespace std;

/* function::Heapify(array, size, index) */
void Heapify (int a[], int n, int index) {
	// Get max value and left, right childs
	int max = index;
	int left = 2*index + 1;
	int right = 2*index + 2;
	
	// Check for max value position
	if (left<n && a[left]>a[max]) max = left;
	if (right<n && a[right]>a[max]) max = right;
	
	// If child has max value then Heapify child after swapping to parent
	if (max != index) {
		int tmp = a[index];
		a[index] = a[max];
		a[max] = tmp;
		
		// Heapify the newly swapped child node
		Heapify(a, n, max);
	}
} // #EndOfHeapify!

/* function::HeapSort(array, size) */
void HeapSort (int a[], int n) {
	// Heapify elements that are being inserted
	for(int i=(n/2)-1; i>=0; i--)
		Heapify(a, n, i);
	
	// Heapify root
	for(int i=n-1; i>=0; i--) {
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		
		Heapify(a, i, 0);
	}
} // #EndOfHeapSort!

/* function::main() */
int main() {
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
		
	// Heap sort function call
	HeapSort(a, n);
	
	// Printing Array after sorting
	printf("After Sorting\n");
	for(int i=0; i<n; i++) 
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
