#include<stdio.h>
using namespace std;

/* function::CountingSort(array, start index, end index) */
void CountingSort (int a[], int n) {
	// find min and max elements in array
	int max = 0;
	unsigned int min = -1;
	for(int i=0; i<n; i++) {
		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];	
	}
	
	// Create a temp array to store counts of each value from min to max
	int tmp[max-min+1];
	for(int i=0; i<(max-min+1); i++) 
		tmp[i] = 0;
	
	// Read the actual array and increment the count of the number by 1 in tmp array
	for(int i=0; i<n; i++) 
		tmp[a[i]-min]++;
		
	// Sorted array being printed out
	printf("After Sorting\n");
	for(int i=0; i<(max-min+1); i++) {
		while(tmp[i] > 0) {
			printf("%d ", i+min);
			tmp[i]--;
		}
	} printf("\n");
} // #EndOfCountingSort!

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
		
	// Counting sort function call
	CountingSort(a, n);
} // #EndOfMain!
