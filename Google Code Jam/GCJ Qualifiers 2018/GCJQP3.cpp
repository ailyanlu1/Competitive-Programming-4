#include<cmath>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef vector<vector<bool> > BoolMatrix;
typedef vector<vector<unsigned int> > IntMatrix;

void shrink (IntMatrix &intMatrix, int x, int y) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int X = x + j - 1;
			int Y = y + i - 1;
			
			if ((Y < 0 || X < 0) 
				|| (X >= intMatrix[0].size() || Y >= intMatrix.size())) continue;
			
			intMatrix[Y][X]--;
		}
	}
}

void searchResult (IntMatrix &intMatrix, int go, int &x, int& y) {
	int X, Y, max = 0, a = intMatrix[0].size(), b = intMatrix.size();
	for (y = 1; y < b - 1; y++) {
    	for (x = 1; x < a - 1; x++) {
			int tmp = intMatrix[y][x];
			
			if (tmp == go) return;
			
			if (tmp > max) { 
				max = tmp;
				X = x;
				Y = y; 
			}
		}
	}
	
	x = X;
	y = Y;
}

void solve () {
	int i, j, need, att = 0, prep = 0, go = 9;
	cin >> need;
	
	if (need != 20) { 
		i = 8; 
		j = 25; 
	}
	else { 
		i = 5; 
		j = 4; 
	}
	
	BoolMatrix boolMatrix (50, vector<bool>(50, 0));
	IntMatrix intMatrix (j, vector<unsigned int>(i, 9));
	while (att < 1000 && prep < need) {
		int a, b, x = 1, y = 1;
		
		searchResult(intMatrix, go, x, y);
		
		go = intMatrix[y][x];
		
		cout << y + 1 << " " << x + 1 << endl;
		fflush(stdout);
		cin >> b >> a;
		
		if (a == 0 && b == 0) return;
		if (a == -1 && b == -1) exit(0);
		
		att++;
		if (boolMatrix[b][a]) continue;
		
		prep++;
		boolMatrix[b][a] = true;
		shrink(intMatrix, a, b);
	}
}

int main () {
	int testCases;
	cin >> testCases;
	
	for (int test = 1; test <= testCases; test++) solve();
}
