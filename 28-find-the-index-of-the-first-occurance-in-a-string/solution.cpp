
#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
	int strStr(std::string haystack, std::string needle) {
		if (needle.size() > haystack.size()) return -1;

		for (size_t startIdx = 0; startIdx < haystack.size() - needle.size() + 1; startIdx++)
		{
			if (haystack.substr(startIdx, needle.size()) == needle) return startIdx;
		}

		return -1;
	}
};

int main() {
	Solution sol;

	std::string haystack, needle;
	int answer, output;

	haystack = "sadbutsad", needle = "sad";
	answer = 0;
	output = sol.strStr(haystack, needle);
	std::cout << needle << " in " << haystack << ": " << (answer == output) << std::endl;

	haystack = "satbudsad", needle = "sad";
	answer = 6;
	output = sol.strStr(haystack, needle);
	std::cout << needle << " in " << haystack << ": " << (answer == output) << std::endl;

	haystack = "leetcode", needle = "leeto";
	answer = -1;
	output = sol.strStr(haystack, needle);
	std::cout << needle << " in " << haystack << ": " << (answer == output) << std::endl;

	haystack = "a", needle = "a";
	answer = 0;
	output = sol.strStr(haystack, needle);
	std::cout << needle << " in " << haystack << ": " << (answer == output) << std::endl;

	haystack = "ab", needle = "b";
	answer = 1;
	output = sol.strStr(haystack, needle);
	std::cout << needle << " in " << haystack << ": " << (answer == output) << std::endl;

	haystack = "ab", needle = "c";
	answer = -1;
	output = sol.strStr(haystack, needle);
	std::cout << needle << " in " << haystack << ": " << (answer == output) << std::endl;

	haystack = "abb", needle = "abaaa";
	answer = -1;
	output = sol.strStr(haystack, needle);
	std::cout << needle << " in " << haystack << ": " << (answer == output) << std::endl;
}
