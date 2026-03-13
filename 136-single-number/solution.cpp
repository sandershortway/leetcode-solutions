#include <iostream>
#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    int remainingNum = 0;
    for (const int &num : nums) {
      remainingNum ^= num;
    }
    return remainingNum;
  }
};

int main() {
  Solution sol;
  std::vector<int> test{1, 2, 1};

  std::cout << sol.singleNumber(test) << std::endl;
}