# 90. Subsets II
from collections import Counter


class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)
        result, solution = [], []

        def backtrack(index: int) -> None:
            if (index >= len(nums)):
                if solution not in result:
                    result.append(solution.copy())
                return

            solution.append(nums[index])
            index += 1
            backtrack(index)
            solution.pop()
            backtrack(index)

        backtrack(0)
        return result




sol = Solution()

# Test case 1
nums = [1, 2, 2]
output = sol.subsetsWithDup(nums)
answer = [[],[1],[1,2],[1,2,2],[2],[2,2]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 2
nums = []
output = sol.subsetsWithDup(nums)
answer = [[]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 3
nums = [1]
output = sol.subsetsWithDup(nums)
answer = [[],[1]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 4
nums = [4,4,4,1,4]
output = sol.subsetsWithDup(nums)
answer = [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)