#include<stdio.h>
using namespace std;

/* function::LinearSearch(array, size, searchValue) */
int LinearSearch (int a[], int n, int toSearch) {
	// Iterate over the array
	for(int i=0; i<n; i++) {
		// If the value is found, return the index
		if (a[i] == toSearch)
			return i;
	}
	
	// If value is not found return -1
	return -1;
} // #EndOfLinearSearch!

/* function::main() */
int main ( ) {
	// Making file stream as input stream
	freopen("input.txt", "r", stdin);
	
	// Reading number of elements in an array to search from
	int n;
	scanf("%d", &n);
	
	// Reading array and printing values before sorting them
	int a[n];
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		printf("%d ", a[i]);
	} printf("\n\n");
	
	// Read the value that is to be searched
	int toSearch;
	scanf("%d", &toSearch);
	
	// Linear Search function call
	int steps = LinearSearch(a, n, toSearch);

	// If value is found in array, determine steps otherwise print that it was not found
	steps != -1? printf("Steps: %d\n", steps) : printf("value doesn't exist\n");
} // #EndOfMain!
