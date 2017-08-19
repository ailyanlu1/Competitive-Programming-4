#include<stdio.h>
#include<windows.h>
using namespace std;

int binarySearch (int a[], int start, int end, int toSearch, int steps) {
	if (end >= start) {
		int index = start + (end-start)/2;
		
		if (a[index] == toSearch) return steps;
		else if (a[index] < toSearch) return binarySearch(a, index+1, end, toSearch, steps+1);
		else return binarySearch(a, start, index-1, toSearch, steps+1);
	}
	
	return -1;
}

int main ( ) {
	freopen("input.txt", "r", stdin);
	
	int n;
	scanf("%d", &n);
	
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
		
	int toSearch;
	scanf("%d", &toSearch);
	
	int steps = binarySearch(a, 0, n-1, toSearch, 0);
	
	steps != -1? printf("Steps: %d\n", steps) : printf("value doesn't exist\n");
}
