#include<stdio.h>
#include<math.h>
using namespace std;

int jumpSearch (int a[], int n, int toSearch) {
	bool found = false;
	int index = 0, steps = 0;
	while (!found && index<n) {
		if (a[index] == toSearch) return steps;
		else if (a[index] < toSearch) index += sqrt(n);
		else if (a[index] > toSearch) {
			for (int i=index-sqrt(n)+2; i<index; i++) {
				if (a[i] == toSearch) return steps;
				
				steps++;
			}
			
			found = true;
		}
		
		steps++;
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
	
	int steps = jumpSearch(a, n, toSearch);
	
	steps != -1? printf("Steps: %d\n", steps) : printf("value doesn't exist\n");
}
