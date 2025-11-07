import numpy as np


class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_string = str(x)
        length = len(x_string)
        half = np.floor(length / 2)

        for i in range(int(half)):
            if x_string[i] != x_string[-1 - i]:
                return False
        return True
