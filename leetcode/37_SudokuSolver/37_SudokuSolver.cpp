#include <bits/stdc++.h>

using namespace std;

bool checkCell(vector<vector<char>>& board, char selected, int row, int col) {
	// Check this value against the row, column, and box it stays inside
	for (int i = 0; i < board.size(); i++) {
		// Row
		if (row != i && selected == board[i][col])
			return false;
		// Column
		if (col != i && selected == board[row][i])
			return false;
		// Box
		int boxRow = (row / 3) * 3 + i / 3;
		int boxCol = (col / 3) * 3 + i % 3;
		if ((boxRow != row || boxCol != col) && selected == board[boxRow][boxCol])
			return false;
	}
	return true;
}

bool checkBoard(vector<vector<char>>& board) {
	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board[row].size(); col++) {
			if (!checkCell(board, board[row][col], row, col))
				return false;
		}
	}
	return true;
}

bool solve(vector<vector<char>> &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == '.') {
				for (char c = '1'; c <= '9'; c++) {
					if (checkCell(board, c, i, j)) {
						// Try this value
						board[i][j] = c;

						if (solve(board))
							// If no dots are left everything fits => solution found
							return true;
						else
							// Backtrack
							board[i][j] = '.';
					}
				}
				// 1-9 didn't work => dead end, a previous value probably was wrong
				return false;
			}
		}
	}
	// No dots left => solution found
	return true;
}

void solveSudoku(vector<vector<char>>& board) {
	if (!solve(board))
		cout << "No solution exists for this board" << endl;
}

int main() {
	/*
	* Input: board =
	* [
	*	["5","3",".",".","7",".",".",".","."],
	*	["6",".",".","1","9","5",".",".","."],
	*	[".","9","8",".",".",".",".","6","."],
	*	["8",".",".",".","6",".",".",".","3"],
	*	["4",".",".","8",".","3",".",".","1"],
	*	["7",".",".",".","2",".",".",".","6"],
	*	[".","6",".",".",".",".","2","8","."],
	*	[".",".",".","4","1","9",".",".","5"],
	*	[".",".",".",".","8",".",".","7","9"]
	* ]
	* Output:
	* [
	*	["5","3","4","6","7","8","9","1","2"],
	*	["6","7","2","1","9","5","3","4","8"],
	*	["1","9","8","3","4","2","5","6","7"],
	*	["8","5","9","7","6","1","4","2","3"],
	*	["4","2","6","8","5","3","7","9","1"],
	*	["7","1","3","9","2","4","8","5","6"],
	*	["9","6","1","5","3","7","2","8","4"],
	*	["2","8","7","4","1","9","6","3","5"],
	*	["3","4","5","2","8","6","1","7","9"]
	* ]
	* Explanation: see https://leetcode.com/problems/sudoku-solver/description/
	*/

	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	solveSudoku(board);

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
			if (j+1 < board[i].size() && (j+1) % 3 == 0)
				cout << "| ";
		}
		if (i+1 < board.size() && (i+1) % 3 == 0) {
			cout << '\n';
			for (int k = 0; k < board[i].size() + (board[i].size()-1) / 3; k++) {
				cout << "- ";
			}
		}
		cout << '\n';
	}
}
