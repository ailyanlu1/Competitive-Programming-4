#include<iostream>
using namespace std;

int main () {
	freopen("Q2.txt", "r", stdin);
	
	int testCases;
	cin >> testCases;
	
    for (int test = 1; test <= testCases; test++) {
    	int n, index;
    	cin >> n;
    	
    	int array[n];
    	for (int i = 0; i < n; i++) cin >> array[i];
    	
	    bool done = false;
	    while (!done) {
	    	done = true;
	    	
	    	for (int i = 0; i < n - 2; i++) {
	    		if (array[i] > array[i + 2]) {
					done = false;
					
					int tmp = array[i];
					array[i] = array[i + 2];
					array[i + 2] = tmp;
				}
			}
	    }
		
		bool solution = true;
		for (int i = 0; i < n - 1 && solution; i++) {
			if (array[i] > array[i + 1]) {
				solution = false;
				index = i;
			}
		}
        
        if (solution) cout << "Case #" << test << ": OK" << endl;
        else cout << "Case #" << test << ": " << index << endl;
	}
}

