#include<iostream>
using namespace std;

/* function::Hash(string) */
int Hash (std::string str) {
	int hash = 0;
	for(int i=0; i<str.length(); i++) 
		hash += (i+1)*str[i];
		
	return hash;
} // #EndOfHash!

/* function::RabinKarp(string, pattern) */
bool RabinKarp (std::string str, std::string pattern) {
	int patternHash = Hash(pattern);
	
	for(int i=0; i<=str.length()-pattern.length(); i++) {
		std::string substring = str.substr(i, pattern.length());
		
		int substringHash = Hash(substring);
		
		if (patternHash == substringHash) {
			int j=0, k=i;
			while (pattern[j] == str[k]) {
				k++;
				j++;
				
				if (j==pattern.length()) return true;
				else if (j>pattern.length()) continue;
			}
		}
	}
	
	return false;
} // #EndOfRabinKarp!

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
		
		// Rabin Karp function call
		bool found = RabinKarp(str, pattern);
		
		// If found print exists; else doesn't exist
		found? printf("Pattern exists!\n\n") : printf("Pattern doesn't exist!\n\n");
	}
} // #EndOfMain!
