#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

// function::FindDigits(number) */
int FindDigits (int n) {
	int digits = 0;
	while (n != 0) {
		n /= 10;
		digits++;
	} return digits;
} // #EndOfFindDigits

// function::FindMaxDigits(array, size) */
int FindMaxDigits (int a[], int n) {
	int max = 0;
	for(int i=0; i<n; i++) {
		if (max < a[i]) max = a[i];
	}
	
	return FindDigits(max);
} // #EndOfFindMaxDigits!

/* function::RadixSort(array, size, currentDigit, maxDigit) */
void RadixSort(int a[], int n, int currentDigit, int maxDigit) {
	// Check if you have max number of digits
	if (currentDigit <= maxDigit) {
		// Create 10 buckets
		vector<int> bucket[10];
		
		// Populate each bucket
		for(int i=0; i<n; i++) {
			int digit = (a[i]/((int)pow(10, maxDigit-currentDigit)))%10;
			bucket[digit].push_back(a[i]);
		}
		
		// Print sorted data
		if (currentDigit == maxDigit) {
			for(int i=0; i<10; i++) {
				for(int j=0; j<bucket[i].size(); j++)
					printf("%d ", bucket[i][j]);
			}
		}
		
		// Call RadixSort if bucket has some values
		for(int i=0; i<10; i++) {
			if (bucket[i].size() > 0) {
				int tmp[bucket[i].size()];
				for(int j=0; j<bucket[i].size(); j++) 
					tmp[j] = bucket[i][j];
				
				// Recursive RadixSort call on new bucket
				RadixSort(tmp, bucket[i].size(), currentDigit+1, maxDigit);
			}
		}
	} 
} // #EndOfBucketSort!

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
	
	// Find Max digits to generate buckets
	int maxDigits = FindMaxDigits(a, n);
	
	printf("After Sorting\n");
	
	// Radix Sort function call
	RadixSort(a, n, 1, maxDigits);

	// Filler line feed
	printf("\n");
}
