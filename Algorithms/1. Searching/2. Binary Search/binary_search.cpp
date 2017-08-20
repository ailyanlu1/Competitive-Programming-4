#include<stdio.h>
using namespace std;

/* function::BinarySearch(array, start index, end index, searchValue, steps) */
int BinarySearch (int a[], int start, int end, int toSearch, int steps) {
	// If starting index is less than end index
	if (end >= start) {
		// find mid index of an array
		int index = start + (end-start)/2;
		
		// Check if value of mid index is greater, lesser or equal to the search value
		if (a[index] == toSearch) return steps;
		else if (a[index] < toSearch) return BinarySearch(a, index+1, end, toSearch, steps+1);
		else return BinarySearch(a, start, index-1, toSearch, steps+1);
	}
	
	// return -1 if value isn't found in array
	return -1;
} // #EndOfBinarySearch!

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
	
	// Binary Search function call
	int steps = BinarySearch(a, 0, n, toSearch, 0);

	// If value is found in array, determine steps otherwise print that it was not found
	steps != -1? printf("Steps: %d\n", steps) : printf("value doesn't exist\n");
} // #EndOfMain!
