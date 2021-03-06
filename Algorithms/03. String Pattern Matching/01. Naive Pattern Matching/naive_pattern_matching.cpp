#include<iostream>
using namespace std;

// This class is used to check if pattern exists in a string
// and how many comparisons were made to find pattern in a string
class Pair {
	public:
		bool exists;
		int comparison;
		
		Pair() {
			exists = false;
			comparison = 0;
		}
};

/* function::NaivePatternMatching(string, pattern) */
Pair NaivePatternMatching (std::string str, std::string pattern) {
	Pair result;
	
	// iterate over the strings until pattern iterates over every match on the string
	for (int i=0; i<=str.size()-pattern.size(); i++) {
		// check if pattern exist
		int j=0, k=i;
		while (str[k]==pattern[j]) {
			k++;
			j++;
			result.comparison++;
			
			// if j has reached its length; therefore pattern exists
			if (j==pattern.size()) {
				// set exists to true; since pattern exists in string
				result.exists = true;
				
				// print where pattern occurs in a string
				std::cout << "Pattern exists at index: " << k-j << std::endl;
				std::cout << str << std::endl;
				for (int l=1; l<=k-j; l++) cout << " ";
				std::cout << pattern << std::endl << std::endl;
			}
		}
		
		if (j<pattern.length()) result.comparison++;
	}
	
	// return exists
	return result;
} // #EndOfNaivePatternMatching!

/* function::main() */
int main ( ) {
	// change console input stream to filestream input
	freopen("input.txt", "r", stdin);
	
	int counter = 1;
	std::string str, pattern;
	
	// while filestream isn't empty, read string and pattern
	while (std::getline(std::cin, str)) {
		std::getline(std::cin, pattern);
		
		// print the case, pattern and the string
		std::cout << "-----Case#" << counter++ << "-----" << std::endl;
		std::cout << "Pattern: " << pattern << std::endl;
		std::cout << "String: " << str << std::endl << std::endl;
		
		// Naive Pattern Matching function call
		Pair result = NaivePatternMatching(str, pattern);
		
		// print total number of comparisons
		std::cout << "Total Comparisons: " << result.comparison << std::endl;
		
		// print whether pattern exists or not according to exists variable value
		std::cout << "Verdict: " << (result.exists? "Pattern exists!" : "Pattern doesn't exist") << std::endl << std::endl; 
	}
} // #EndOfMain!
