#include<stdio.h>
using namespace std;

/* function::CombSort(array, size) */
void CombSort (int a[], int n) {
	// start with max gap
	int gap = n;
	bool swapped = true;
	
	// while gap isn't 1 or value is swapped
	while (swapped || gap!=1) {
		// calculate value of gap
		gap = gap*10/(float)13;
		gap<1? gap = 1 : gap = gap;
		swapped = false;
		
		// apply gapped bubble sort algorithm
		for(int i=0; i<n-gap; i++) {
			if (a[i] > a[i+gap]) {
				int tmp = a[i];
				a[i] = a[i+gap];
				a[i+gap] = tmp;
				
				swapped = true;
			}
		}
	}
} // #EndOfCombSort!

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
		
	// Comb sort function call
	CombSort(a, n);
	
	// Printing values after applying selection sort algorithm
	printf("After Sorting\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
