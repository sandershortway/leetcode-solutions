# 40. Combination Sum II
from collections import Counter


class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        result, solution = [], []
        candidates.sort()

        def backtrack(idx: int) -> None:
            s = sum(solution)
            if (s > target):
                return

            if (s == target):
                if solution not in result:
                    result.append(solution.copy())
                return

            for i in range(idx, len(candidates)):
                solution.append(candidates[i])
                backtrack(i+1)
                solution.pop()

        backtrack(0)
        return result


sol = Solution()

# Test case 1
candidates = [10, 1, 2, 7, 6, 1, 5]
target = 8
output = sol.combinationSum2(candidates, target)
answer = [[1,1,6],[1,2,5],[1,7],[2,6]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 2
candidates = [2, 5, 2, 1, 2]
target = 5
output = sol.combinationSum2(candidates, target)
answer = [[1,2,2],[5]]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 3
candidates = [2]
target = 1
output = sol.combinationSum2(candidates, target)
answer = []
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 4 -- Fails time limit, more intelligent pruning required
candidates = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
target = 30
output = sol.combinationSum2(candidates, target)
answer = []
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)
