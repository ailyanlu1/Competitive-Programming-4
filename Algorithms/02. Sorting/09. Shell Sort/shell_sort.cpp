#include<stdio.h>
using namespace std;

/* function::ShellSort(array, size) */
void ShellSort (int a[], int n) {
	// Start with half gap and reduce it by half in each iteration
	for(int i=n/2; i>0; i/=2) {
		// Gapped Insertion Sort
		for(int j=i; j<n; j++) {
			int k, key = a[j];
			
			// Swap if key is smaller than gapped array value
			for(k=j; k>=i && a[k-i]>key; k-=i) 
				a[k] = a[k-i];
			
			// Set the key to its appropriate position
			a[k] = key;
		}
	}
} // #EndOfShellSort!

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
		
	// Shell sort function call
	ShellSort(a, n);
	
	
	printf("After Sorting\n");
	for(int i=0; i<n; i++) 
		printf("%d ", a[i]);
	printf("\n");
} // #EndOfMain!
