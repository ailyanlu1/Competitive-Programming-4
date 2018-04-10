#include<iostream>
using namespace std;

int main () {
	freopen("Q1.txt", "r", stdin);
	
	int testCases;
	cin >> testCases;
	
    for (int test = 1; test <= testCases; test++) {
    	int tries = 0, damage = 0, power = 1, shield;
        string pattern;
        
        cin >> shield;
        cin >> pattern;
            
        for (int i = 0; i < pattern.length(); i++) {
            if (pattern[i] == 'C') power *= 2;
            else damage += power;
    	}
    	
        bool solution = false;
        for (int i = pattern.length() - 1; i > 0 && damage > shield; i--) {
            if (pattern[i] == 'S' && pattern[i - 1] == 'C') {
            	pattern[i - 1] = 'S';
        		damage -= (power / 2);
				tries++;
				
				int j = i + 1;
				while (damage > shield && j < pattern.length() && pattern[j] == 'S') {
					j++;
					damage -= (power / 2);
					tries++;
				}
				
				power /= 2;
            } else if (pattern[i] == 'C') power /= 2;
        }
        
        if (damage > shield) cout << "Case #" << test << ": " << "IMPOSSIBLE" << endl;
        else cout << "Case #" << test << ": " << tries << endl;
	}
}

