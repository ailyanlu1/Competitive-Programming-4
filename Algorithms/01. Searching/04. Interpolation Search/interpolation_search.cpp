#include<stdio.h>
using namespace std;

/* function::InterpolationSearch(array, start index, end index, searchValue, steps) */
int InterpolationSearch (int a[], int start, int end, int toSearch, int steps) {
	// If start index is less than end index
	if (end >= start) {
		// Set pointing index
		int index = start + (((double)(end-start) / (a[end]-a[start]))*(toSearch-a[start]));
		
		// Check if index is greater, lesser or equal to the value that is being searched
		if (a[index] == toSearch) return steps;
		else if (a[index] < toSearch) return InterpolationSearch(a, index+1, end, toSearch, steps+1);
		else return InterpolationSearch(a, start, index-1, toSearch, steps+1);
	}
	
	// return -1 if no value exists
	return -1;
} // #EndOfInterpolationSearch!

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
	
	// Interpolation Search function call
	int steps = InterpolationSearch(a, 0, n, toSearch, 0);

	// If value is found in array, determine steps otherwise print that it was not found
	steps != -1? printf("Steps: %d\n", steps) : printf("value doesn't exist\n");
} // #EndOfMain!
