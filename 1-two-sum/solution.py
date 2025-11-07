from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for i in range(len(nums)):
            current_num = nums[i]

            if target - current_num in seen:
                return [i, seen[target - current_num]]

            seen[current_num] = i
