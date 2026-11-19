"""22. Generate Parentheses"""

from collections import Counter

def is_valid(s: str) -> bool:
    """Checks if combination of parantheses is well-formed."""
    n = 0
    for c in s:
        if c == "(":
            n += 1
        if c == ")":
            n += -1

        if (n < 0):
            return False
    return n == 0

class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        solution = ""

        def backtrack() -> None:
            nonlocal solution

            if (len(solution) >= 2*n):
                if (is_valid(solution)):
                    result.append(solution)
                return

            for char in ['(', ')']:
                solution += char
                backtrack()
                solution = solution[:-1]

        backtrack()
        return result

sol = Solution()

# Test case 1
n = 3
output = sol.generateParenthesis(n)
answer = ["((()))","(()())","(())()","()(())","()()()"]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 2
n = 1
output = sol.generateParenthesis(n)
answer = ["()"]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)
