
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution {
public:
	std::string longestPalindrome(std::string s) {
		const unsigned int len = s.size();

		// Init variables for keeping track of longest palindrome so far
		int bestLen = 0;
		int bestLenStartIdx = 0;

		// Init 2d array for keeping track of known palindromes
		std::vector<std::vector<bool>> p(len, std::vector<bool>(len, false));

		// Loop through each substring length (starting from 1)
		for (size_t subLen = 1; subLen <= len; subLen++)
		{
			// Loop through all possible left starting values
			for (size_t left = 0; left <= len - subLen; left++)
			{
				int right = left + subLen - 1;
				bool innerSubstringExists = right - left > 1;

				if (s.at(left) == s.at(right)) {
					if ((innerSubstringExists && p.at(left + 1).at(right - 1)) || !innerSubstringExists) {
						// In the first condition: As no inner substring exist and outer values match, this substring is palindromic
						// In the second condition: As outer values match, substring is palindromic if inner substring is palindromic
						p.at(left).at(right) = true;
						bestLen = subLen;
						bestLenStartIdx = left;
					}
				}
			}
		}

		return s.substr(bestLenStartIdx, bestLen);
	}
};

int main() {
	Solution sol;

	std::string s = "babad";
	std::string solution = sol.longestPalindrome(s);
	bool correct = solution == "bab" || solution == "aba";
	std::cout << "'" << s << "'" << " - " << correct << std::endl;

	s = "";
	solution = sol.longestPalindrome(s);
	correct = solution == "";
	std::cout << "'" << s << "'" << " - " << correct << std::endl;

	s = "babax";
	solution = sol.longestPalindrome(s);
	correct = solution == "bab" || solution == "aba";
	std::cout << "'" << s << "'" << " - " << correct << std::endl;

	s = "abba";
	solution = sol.longestPalindrome(s);
	correct = solution == "abba";
	std::cout << "'" << s << "'" << " - " << correct << std::endl;

	s = "cbbd";
	solution = sol.longestPalindrome(s);
	correct = solution == "bb";
	std::cout << "'" << s << "'" << " - " << correct << std::endl;

	s = "abc";
	solution = sol.longestPalindrome(s);
	correct = (solution == "a") || (solution == "b") || (solution == "c");
	std::cout << "'" << s << "'" << " - " << correct << std::endl;


}
