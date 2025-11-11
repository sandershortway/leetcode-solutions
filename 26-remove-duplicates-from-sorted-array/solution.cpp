
#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 1;

        int prevMaxIdx = 0;
        int prevMax = nums.at(prevMaxIdx);

        for (size_t idx = 1; idx < nums.size(); idx++)
        {
            if (nums.at(idx) > prevMax) {
                prevMax = nums.at(idx);
                nums.at(++prevMaxIdx) = prevMax;
            }
        }

        return ++prevMaxIdx;
    }
};

int main() {
    Solution sol;

    std::vector<int> one = { 0, 0, 1, 1, 1, 2, 2 };
    int k = sol.removeDuplicates(one);

    std::vector<int> two = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    k = sol.removeDuplicates(two);

    std::vector<int> three;
    k = sol.removeDuplicates(three);
}