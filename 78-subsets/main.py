# 78. Subsets
from collections import Counter


class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        result = []

        def backtrack(current: list[int], index: int) -> None:
            if (index >= len(nums)):
                result.append(current.copy())
                return

            current.append(nums[index])
            index += 1
            backtrack(current, index)
            current.pop()
            backtrack(current, index)

        backtrack([], 0)
        return result




sol = Solution()

# Test case 1
nums = [1, 2, 3]
output = sol.subsets(nums)
answer = [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 2
nums = []
output = sol.subsets(nums)
answer = [[]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 3
nums = [1]
output = sol.subsets(nums)
answer = [[],[1]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)