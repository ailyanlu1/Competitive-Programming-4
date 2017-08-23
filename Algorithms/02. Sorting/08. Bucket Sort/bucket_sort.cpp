#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

/* function::FindMaxDigit(array, size) */
int FindMaxDigit (int a[], int n) {
	int max = 0, digits = 0;
	for(int i=0; i<n; i++) {
		if (a[i] > max) max = a[i];
	}
	
	while (max != 0) {
		max /= 10;
		digits++;
	}
	
	return digits;
} // #EndOfFindMaxDigit!

/* function::BucketSort(array, size) */
void BucketSort (int a[], int n) {
	// Create buckets
	vector<int> bucket[10];
	
	// Find number of digits max value has
	int maxDigit = FindMaxDigit(a, n);
	
	// Fill each bucket
	for(int i=0; i<n; i++) {
		int index = a[i]/pow(10, maxDigit-1);
		bucket[index].push_back(a[i]);
	}
	
	// Apply insertion sort on each bucket
	for(int i=0; i<10; i++) {
		for(int j=1; j<bucket[i].size(); j++) {
			int k = j-1;
			int key = bucket[i][j];
			
			while (k>=0 && a[k]>key) {
				bucket[i][k+1] = bucket[i][k];
				k--;
			}
			
			bucket[i][k+1] = key;
		}
	}
	
	// Print the result
	printf("After Sorting\n");
	for(int i=0; i<10; i++) {
		for(int j=0; j<bucket[i].size(); j++) 
			printf("%d ", bucket[i][j]);
	}
	printf("\n");
} // #EndOfBucketSort!

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
		
	// Bucket sort function call
	BucketSort(a, n);
} // #EndOfMain!
