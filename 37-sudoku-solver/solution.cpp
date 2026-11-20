
#include <array>
#include <cassert>
#include <stdexcept>
#include <vector>

using namespace std;

class Solution
{
private:
	bool isValid(const vector<vector<char>> &board)
	{
		array<array<bool, 9>, 9> rows{};
		array<array<bool, 9>, 9> columns{};
		array<array<bool, 9>, 9> blocks{};

		for (int row = 0; row < 9; ++row)
		{
			for (int col = 0; col < 9; ++col)
			{
				if (board[row][col] == '.')
					continue;

				int digit = board[row][col] - '1';
				int block = (row / 3) * 3 + col / 3;
				if (rows[row][digit] || columns[col][digit] || blocks[block][digit])
					return false;

				rows[row][digit] = true;
				columns[col][digit] = true;
				blocks[block][digit] = true;
			}
		}
		return true;
	}

	bool backtrack(vector<vector<char>> &board)
	{
		if (!isValid(board))
			return false;

		for (int row = 0; row < 9; ++row)
		{
			for (int col = 0; col < 9; ++col)
			{
				if (board[row][col] == '.')
				{
					for (char digit = '1'; digit <= '9'; ++digit)
					{
						board[row][col] = digit;
						if (backtrack(board))
							return true;
						board[row][col] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}

public:
	void solveSudoku(vector<vector<char>> &board)
	{
		if (!backtrack(board))
			throw invalid_argument("Sudoku board has no solution");
	}
};

int main()
{
	Solution sol;

	const vector<vector<char>> solvedBoard = {
		{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
		{'6', '7', '2', '1', '9', '5', '3', '4', '8'},
		{'1', '9', '8', '3', '4', '2', '5', '6', '7'},
		{'8', '5', '9', '7', '6', '1', '4', '2', '3'},
		{'4', '2', '6', '8', '5', '3', '7', '9', '1'},
		{'7', '1', '3', '9', '2', '4', '8', '5', '6'},
		{'9', '6', '1', '5', '3', '7', '2', '8', '4'},
		{'2', '8', '7', '4', '1', '9', '6', '3', '5'},
		{'3', '4', '5', '2', '8', '6', '1', '7', '9'}};

	vector<vector<char>> board = solvedBoard;
	sol.solveSudoku(board);
	assert(board == solvedBoard);

	board[0][0] = '.';
	sol.solveSudoku(board);
	assert(board == solvedBoard);

	board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
	sol.solveSudoku(board);
	assert(board == solvedBoard);
}
