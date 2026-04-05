#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

bool backtrack(vector<vector<char>> &board, string word, int row, int column, int idx) {
	// Left, right, up, down
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	if (idx == word.length()) {
		return true;  // Found a "snake" that matches our word
	}

	// Check bounds
	if (row < 0 || row >= board.size() || column < 0 || column >= board[0].size()) {
		return false;
	}

	// Check if the passed letter fits to the word
	if (word[idx] != board[row][column]) {
		return false;
	}

	// Mark cell as visited
	char temp = board[row][column];
	board[row][column] = '#'; 

	// Start the search in the 4 directions
	for (int i = 0; i < 4; i++) {
		if (backtrack(board, word, row + dx[i], column + dy[i], idx + 1)) {
			return true;
		}
	}

	// Backtrack: bring back the substituted characters for other tries
	board[row][column] = temp;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == word[0]) {
				// Can begin a search
				if (backtrack(board, word, i, j, 0)) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	// board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
	vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	string word = "SEE";

	cout << (exist(board, word) ? "EXISTS\n" : "NOPE\n");
}
