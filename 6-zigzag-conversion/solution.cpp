
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

void printGrid(const std::vector<std::vector<char>>& grid)
{
	for (size_t row = 0; row < grid.size(); row++)
	{
		for (size_t col = 0; col < grid.at(0).size(); col++)
		{
			std::cout << grid.at(row).at(col);
		}
		std::cout << std::endl;
	}
}

class Solution {
public:
	std::vector<std::vector<char>> generateGrid(const std::string& s, int numRows) {
		std::vector<std::vector<char>> grid(numRows, std::vector<char>(s.size(), ' '));

		int stringIdx = 0, row = 0, col = 0;
		while (stringIdx < s.size()) {
			// Write stringIdx' char at grid[row][col]
			grid.at(row).at(col) = s.at(stringIdx++);

			// Vertical downward movement
			if (col % (numRows - 1) == 0) {
				if (row < numRows - 1)
					row++;
				else {
					col++;
					row--;
				}
			}
			else // Diagonal upward movement
			{
				row--;
				col++;
			}
		}

		return grid;
	}

	std::string convert(std::string s, int numRows) {
		if (numRows == 1) return s;
		
		std::string answer(s.size(), ' ');
		int stringIdx = 0;
		auto grid = generateGrid(s, numRows);

		for (auto row : grid) {
			for (auto c : row) {
				if (c != ' ') {
					answer.at(stringIdx) = c;
					stringIdx++;
				}
			}
		}

		return answer;
	}
};

int main() {
	Solution sol;

	std::string abc = "abcdefghijklmnopqrstuvwxyz";
	auto grid = sol.generateGrid(abc, 5);
	printGrid(grid);
	std::string answer = sol.convert(abc, 5);
	std::cout << answer << std::endl;

	std::string s = "A";
	//printGrid(sol.generateGrid(s, 1));
	answer = sol.convert(s, 1);
	std::cout << answer << std::endl;

	s = "PAYPALISHIRING";
	grid = sol.generateGrid(s, 3);
	printGrid(grid);
	answer = sol.convert(s, 3);
	std::cout << answer << std::endl;
	//std::cout < "PAHNAPLSIIGYIR" << std::endl << std::endl;
}
