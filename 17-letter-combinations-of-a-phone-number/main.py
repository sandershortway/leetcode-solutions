"""17. Letter Combinations of a Phone Number"""

from collections import Counter

# Maps each digit to its possible letters
KEYS = {
    "2": ["a", "b", "c"],
    "3": ["d", "e", "f"],
    "4": ["g", "h", "i"],
    "5": ["j", "k", "l"],
    "6": ["m", "n", "o"],
    "7": ["p", "q", "r", "s"],
    "8": ["t", "u", "v"],
    "9": ["w", "x", "y", "z"],
}


class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        result = []
        sol = ""

        def backtrack() -> None:
            nonlocal sol

            if (len(sol) == len(digits)):
                result.append(sol)
                return

            for letter in KEYS[digits[len(sol)]]:
                sol += letter
                backtrack()
                sol = sol[:-1]

        backtrack()
        return result




sol = Solution()

# Test case 1
digits = "23"
output = sol.letterCombinations(digits)
answer = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 2
digits = "2"
output = sol.letterCombinations(digits)
answer = ["a","b","c"]
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)

# Test case 3
digits = ""
output = sol.letterCombinations(digits)
answer = []
assert Counter(tuple(sorted(subset)) for subset in output) == Counter(
    tuple(sorted(subset)) for subset in answer
)