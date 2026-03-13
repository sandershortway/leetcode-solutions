#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		// Compute total
		int total = 0;
		for (size_t i = 0; i < nums.size() + 1; i++) total ^= i;
		for (int num : nums) total ^= num;
		
		return total;
	}
};

int main() {
	Solution sol;
	std::vector<int> test{ 9,6,4,2,3,5,7,0,1 };

	std::cout << sol.missingNumber(test) << std::endl;
}