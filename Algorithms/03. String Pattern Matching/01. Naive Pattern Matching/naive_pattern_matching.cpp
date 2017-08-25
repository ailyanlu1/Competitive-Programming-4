#include<iostream>
using namespace std;

/* function::NaivePatternMatching(string, pattern) */
bool NaivePatternMatching (std::string str, std::string pattern) {
	// Iterate until index is less than string length minus pattern length
	for(int i=0; i<=str.size()-pattern.size(); i++) {
		// If a match doesn't occur then increment string index
		if (str[i] != pattern[0]) continue;
		
		// else, check if pattern exists
		int j=0, k=i;
		while (str[k]==pattern[j]) {
			k++;
			j++;
			
			// if index j equals pattern length then pattern exists
			if (j==pattern.size()) return true;
		}
	}
	
	// completing the iteration proves that no pattern existed
	return false;
} // #EndOfNaivePatternMatching!

/* function::main() */
int main ( ) {
	// change console input stream to filestream input
	freopen("input.txt", "r", stdin);
	
	// read string and pattern
	std::string str, pattern;
	while (std::getline(std::cin, str)) {
		std::getline(std::cin, pattern);
		
		// print string and pattern
		std::cout << "string:  " << str << std::endl;
		std::cout << "pattern: " << pattern << std::endl;
		
		// Naive Pattern Matching function call
		bool found = NaivePatternMatching(str, pattern);
		
		// If found print exists; else doesn't exist
		found? printf("Pattern exists!\n\n") : printf("Pattern doesn't exist!\n\n");
	}
} // #EndOfMain!
