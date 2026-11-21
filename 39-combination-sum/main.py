# 39. Combination Sum
from collections import Counter


class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        result, solution = [], []

        def backtrack(idx: int) -> None:
            s = sum(solution)
            if (s > target):
                return

            if (s == target):
                result.append(solution.copy())
                return

            for i in range(idx, len(candidates)):
                solution.append(candidates[i])
                backtrack(i)
                solution.pop()

        backtrack(0)
        return result


sol = Solution()

# Test case 1
candidates = [2, 3, 6, 7]
target = 7
output = sol.combinationSum(candidates, target)
answer = [[2,2,3],[7]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 2
candidates = [2, 3, 5]
target = 8
output = sol.combinationSum(candidates, target)
answer = [[2,2,2,2],[2,3,3],[3,5]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 3
candidates = [2]
target = 1
output = sol.combinationSum(candidates, target)
answer = []
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)
