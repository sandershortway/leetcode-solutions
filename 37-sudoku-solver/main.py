"""37. Sudoku Solver"""

from time import perf_counter


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

def possible_valid_values(board: list[list[str]]) -> dict[tuple[int, int], set[str]]:
    """Returns a dictionary with all possible values for empty cells."""
    possible_values = dict()

    for row_idx in range(0,9):
        row_values = set([cell for cell in board[row_idx] if cell != "."])
        for col_idx in range(0,9):
            col_values = set([row[col_idx] for row in board if row[col_idx] != "."])
            
            if (board[row_idx][col_idx] == "."):
                start_row, start_col = (row_idx // 3) * 3, (col_idx // 3) * 3
                block_values = set([
                    board[row][col]
                    for row in range(start_row, start_row + 3)
                    for col in range(start_col, start_col + 3)
                    if board[row][col] != "."
                ])
                pos_values = set([str(i) for i in range(1,10)]) - row_values - col_values - block_values
                possible_values[(row_idx, col_idx)] = pos_values
    return possible_values

class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        possible_values = possible_valid_values(board)

        def backtrack() -> bool:
            """Returns whether the current board can be completed."""
            if not is_valid(board):
                return False

            for position, values in possible_values.items():
                row, col = position
                if board[row][col] != ".":
                    continue

                for value in values:
                    board[row][col] = value
                    if backtrack():
                        return True
                    board[row][col] = "."

                return False

            return True

        if not backtrack():
            raise ValueError("Sudoku board has no solution")

sol = Solution()

solved_board = [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

# Test case 1
board = [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
start = perf_counter()
sol.solveSudoku(board)
end = perf_counter()
print("Test case 1", 1000*(end - start), "ms")
assert(is_valid(board) and is_full(board))
assert(solved_board == board)

# Test case 2
board = [[".","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
start = perf_counter()
sol.solveSudoku(board)
end = perf_counter()
print("Test case 2", 1000*(end - start), "ms")
assert(is_valid(board) and is_full(board))
assert(solved_board == board)

# Test case 3
board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
start = perf_counter()
sol.solveSudoku(board)
end = perf_counter()
print("Test case 3", 1000*(end - start), "ms")
assert(is_valid(board) and is_full(board))
assert(solved_board == board)

# Test case 4
board = [[".",".",".",".",".",".",".",".","."],[".","9",".",".","1",".",".","3","."],[".",".","6",".","2",".","7",".","."],[".",".",".","3",".","4",".",".","."],["2","1",".",".",".",".",".","9","8"],[".",".",".",".",".",".",".",".","."],[".",".","2","5",".","6","4",".","."],[".","8",".",".",".",".",".","1","."],[".",".",".",".",".",".",".",".","."]]
start = perf_counter()
sol.solveSudoku(board)
end = perf_counter()
print("Test case 4", 1000*(end - start), "ms")
assert(is_valid(board) and is_full(board))
