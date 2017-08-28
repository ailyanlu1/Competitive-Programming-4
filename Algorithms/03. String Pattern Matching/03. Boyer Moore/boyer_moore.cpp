#include<iostream>
#include<algorithm>
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

/* function::BoyerMoore(string, pattern) */
Pair BoyerMoore (std::string str, std::string pattern) {
	Pair result;
	
	// bad character heuristic 
	int badChar['z'-'A'];
	for (int i=0; i<'z'-'A'; i++) badChar[i] = -1;
	for (int i=0; i<pattern.length(); i++) 
		badChar[pattern[i]-'z'] = i;
		
	int i = 0;
	// iterate over the complete string
	while (i <= str.length()-pattern.length()) {
		int j = pattern.length()-1;
		
		// if character at pattern index matches character at string index
		while (j>=0 && pattern[j]==str[i+j]) {
			j--;
			result.comparison++;
		}
		
		// if pattern exists
		if (j < 0) {
			result.exists = true;
			
			// print where pattern occurs in a string
			std::cout << "Pattern exists at index: " << i-j-1 << std::endl;
			std::cout << str << std::endl;
			for (int k=1; k<i-j; k++) cout << " ";
			std::cout << pattern << std::endl << std::endl;
				
			i += (i+str.length() < pattern.length()? pattern.length()-badChar[str[i+pattern.length()]-'z'] : 1);
		} else { // if pattern doesn't exist
			result.comparison++;
			i += max(1, j-badChar[str[i+j]-'z']);	
		}
	}
	
	// return result after iterating over complete string
	return result;
} // #EndOfBoyerMoore!

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
		
		// Boyer Moore function call
		Pair result = BoyerMoore(str, pattern);
		
		// print total number of comparisons
		std::cout << "Total Comparisons: " << result.comparison << std::endl;
		
		// print whether pattern exists or not according to exists variable value
		std::cout << "Verdict: " << (result.exists? "Pattern exists!" : "Pattern doesn't exist") << std::endl << std::endl; 
	}
} // #EndOfMain!
