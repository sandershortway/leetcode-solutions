"""37. Sudoku Solver"""

def has_duplicates(l: list[str]) -> bool:
    """Returns if list has duplicates values."""
    return len(l) != len(set(l))

def is_full(board: list[list[str]]) -> bool:
    """Returns if all cells in board are filled."""
    for row in board:
        for cell in row:
            if cell == ".":
                return False
    return True

def is_valid(board: list[list[str]]) -> bool:
    """Returns if (possibly incomplete) board is valid."""
    for row in board:
        if has_duplicates([cell for cell in row if cell != "."]):
            return False

    for col in range(9):
        column = [row[col] for row in board if row[col] != "."]
        if has_duplicates(column):
            return False

    for start_row in range(0, 9, 3):
        for start_col in range(0, 9, 3):
            block = [
                board[row][col]
                for row in range(start_row, start_row + 3)
                for col in range(start_col, start_col + 3)
                if board[row][col] != "."
            ]
            if has_duplicates(block):
                return False

    return True

class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def backtrack() -> bool:
            if not is_valid(board):
                return False

            for i in range(0,9):
                for j in range(0,9):
                    if board[i][j] == ".":
                        for pos in range(1,10):
                            board[i][j] = str(pos)
                            if backtrack():
                                return True
                            board[i][j] = "."
                        return False
            return True

        if not backtrack():
            raise ValueError("Sudoku board has no solution")

sol = Solution()

solved_board = [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

# Test case 1
board = [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
sol.solveSudoku(board)
assert(solved_board == board)

# Test case 2
board = [[".","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
sol.solveSudoku(board)
assert(solved_board == board)

# Test case 3
board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
sol.solveSudoku(board)
assert(solved_board == board)