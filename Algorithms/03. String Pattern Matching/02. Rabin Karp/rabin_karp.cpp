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

/* function::Hash(string) */
int Hash (std::string str) {
	int hash = 0;
	for(int i=0; i<str.length(); i++) 
		hash += (i+1)*str[i];
		
	return hash;
} // #EndOfHash!

/* function::RabinKarp(string, pattern) */
Pair RabinKarp (std::string str, std::string pattern) {
	Pair result;
	int patternHash = Hash(pattern);
	
	// iterate over the string
	for(int i=0; i<=str.length()-pattern.length(); i++) {
		// generate substring
		std::string substring = str.substr(i, pattern.length());
		
		// computer substring's hash value
		int substringHash = Hash(substring);
		
		// compare hash values of substring and pattern
		if (patternHash == substringHash) {
			int j=0, k=i;
			
			// while string matches, increment the value
			while (j<pattern.length() && k<str.length() && pattern[j]==str[k]) {
				k++;
				j++;
				result.comparison++;
				
				if (j==pattern.length()) {
					result.exists=true;
					
					// print where pattern occurs in a string
					std::cout << "Pattern exists at index: " << k-j << std::endl;
					std::cout << str << std::endl;
					for (int l=1; l<=k-j; l++) cout << " ";
					std::cout << pattern << std::endl << std::endl;
				}
			}
			
			// if a mis-match occured then increment 1 failed comparison
			if (j<pattern.length()) result.comparison++;
		}
	}
	
	// return result after iterating the whole string
	return result;
} // #EndOfRabinKarp!

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
		
		// Rabin Karp function call
		Pair result = RabinKarp(str, pattern);
		
		// print total number of comparisons
		std::cout << "Total Comparisons: " << result.comparison << std::endl;
		
		// print whether pattern exists or not according to exists variable value
		std::cout << "Verdict: " << (result.exists? "Pattern exists!" : "Pattern doesn't exist") << std::endl << std::endl; 
	}
} // #EndOfMain!
