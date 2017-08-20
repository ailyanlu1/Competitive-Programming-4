#include<stdio.h>
#include<math.h>
using namespace std;

/* function::JumpSearch(array, size, searchValue) */
int JumpSearch (int a[], int n, int toSearch) {
	bool found = false;
	int index = 0, steps = 0;
	
	// If value is not found, iterate over the array
	while (!found && index<n) {
		if (a[index] == toSearch) return steps;
		else if (a[index] < toSearch) index += sqrt(n);
		else if (a[index] > toSearch) {
			// If value is greather than searching value then we traverse the previous block to search for value
			for (int i=index-sqrt(n)+2; i<index; i++) {
				if (a[i] == toSearch) return steps;
				
				steps++;
			}
			
			found = true;
		}
		
		steps++;
	}
	
	// If value isn't found then return -1	
	return -1;
} // #EndOfJumpSearch!

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
	
	// Jump Search function call
	int steps = JumpSearch(a, n, toSearch);

	// If value is found in array, determine steps otherwise print that it was not found
	steps != -1? printf("Steps: %d\n", steps) : printf("value doesn't exist\n");
} // #EndOfMain!
