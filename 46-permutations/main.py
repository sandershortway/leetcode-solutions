

# 46. Permutations
from collections import Counter


class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        result, solution = [], []

        def backtrack() -> None:
            if (len(solution) >= len(nums)):
                result.append(solution.copy())
                return

            for i in [num for num in nums if num not in solution]:
                solution.append(i)
                backtrack()
                solution.pop()


        backtrack()
        return result




sol = Solution()

# Test case 1
nums = [1, 2, 3]
output = sol.permute(nums)
answer = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 2
nums = []
output = sol.permute(nums)
answer = [[]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 3
nums = [1]
output = sol.permute(nums)
answer = [[1]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 4
nums = [0,1]
output = sol.permute(nums)
answer = [[0,1],[1,0]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)