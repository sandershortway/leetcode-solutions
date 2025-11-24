
#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		int numNonValElements = nums.size();
		for (std::vector<int>::iterator it = nums.begin(); it != nums.end();)
		{
			if (*it == val) {
				numNonValElements--;
				it = nums.erase(it);
			}
			else { it++; }
		}

		return numNonValElements;
	}
};

int main() {
	Solution sol;

	std::vector vec = { 0, 1, 1, 1, 2, 2, 2, 2, 3, 3 };
	int answer = 7;
	int s = sol.removeElement(vec, 1);
	std::cout << (answer == s) << std::endl;

	vec = { 0, 1, 1, 1, 2, 2, 2, 2, 3, 3 };
	answer = 4;
	s = sol.removeElement(vec, 2);
	std::cout << (answer == s) << std::endl;

	vec = { 0, 1, 1, 1, 2, 2, 2, 2, 3, 3 };
	answer = 2;
	s = sol.removeElement(vec, 3);
	std::cout << (answer == s) << std::endl;

	vec = { 0, 1, 1, 1, 2, 2, 2, 2, 3, 3 };
	answer = 1;
	s = sol.removeElement(vec, 0);
	std::cout << (answer == s) << std::endl;

	vec = { 0, 1, 1, 1, 2, 2, 2, 2, 3, 3 };
	answer = 0;
	s = sol.removeElement(vec, 5);
	std::cout << (answer == s) << std::endl;

	vec = { 0, 1, 2, 2, 3, 0, 4, 2 };
	answer = 2;
	s = sol.removeElement(vec, 2);
	std::cout << (answer == s) << std::endl;
}
