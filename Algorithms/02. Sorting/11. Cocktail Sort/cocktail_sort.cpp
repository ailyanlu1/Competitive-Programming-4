#include<stdio.h>
using namespace std;

/* function::CocktailSort(array, size) */
void CocktailSort (int a[], int n) {
	// Set variables
	int counter = 1;
	bool swapped = true, sorted = false, goRight = true;
	
	// Iterating over the array
	for(int i=0; !sorted; i+=counter) {
		// If bubbles are swappable than swap values
		if (a[i]>a[i+1]) {
			int tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp;
			
			swapped = true;
		}
		
		// If pointer has reached end while going right
		// or start while going left, then multiply counter by -1
		// and change the direction
		if (i==n-1 && goRight) {
			goRight = false;
			counter = -1;
			if (!swapped) sorted = true;
			swapped = false;
		} else if (i==0 && !goRight) {
			goRight = true;
			counter = 1;
			if (!swapped) sorted = true;
			swapped = false;
		}
	}
} // #EndOfCocktailSort!

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
		
	// Cocktail sort function call
	CocktailSort(a, n);
	
	// Printing values after applying selection sort algorithm
	printf("After Sorting\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
