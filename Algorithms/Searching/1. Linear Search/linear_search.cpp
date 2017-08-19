#include<stdio.h>
using namespace std;

int linearSearch (int a[], int n, int toSearch) {
	for(int i=0; i<n; i++) {
		if (a[i] == toSearch)
			return i;
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
	
	int steps = linearSearch(a, n, toSearch);

	steps != -1? printf("Steps: %d\n", steps) : printf("value doesn't exist\n");
}
