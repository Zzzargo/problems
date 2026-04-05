#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
 * In this order:
 * 2Left1Down, 2Left1Up, 1Left2Up, 1Right2Up, 2Right1Up, 2Right1Down, 1Left2Down, 1Right2Down
*/
int dx[] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2 ,-2};

int countOnwardMoves(vector<vector<char>> &board, int row, int col) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		int nextRow = row + dy[i];
		int nextCol = col + dx[i];
		if (nextRow >= 0 && nextRow < 8 && nextCol >= 0 && nextCol < 8 && board[nextRow][nextCol] == 0) {
			count++;
		}
	}
	return count;
}

bool backtrack(vector<vector<char>> &board, int row, int col, int currIdx) {
	if (currIdx >= 64) {
		return true;
	}

	// Get all possible moves with their onward move counts (Warnsdorff's heuristic)
	vector<pair<int, int>> moves; // (onward_count, direction_index)
	for (int i = 0; i < 8; i++) {
		int nextRow = row + dy[i];
		int nextCol = col + dx[i];
		if (nextRow >= 0 && nextRow < 8 && nextCol >= 0 && nextCol < 8 && board[nextRow][nextCol] == 0) {
			int onwardCount = countOnwardMoves(board, nextRow, nextCol);
			moves.push_back({onwardCount, i});
		}
	}

	// Sort by onward moves count (ascending)
	sort(moves.begin(), moves.end());

	// Try moves in order of increasing onward moves
	for (auto [count, i] : moves) {
		int nextRow = row + dy[i];
		int nextCol = col + dx[i];
		board[nextRow][nextCol] = currIdx + 1;

		if (backtrack(board, nextRow, nextCol, currIdx + 1)) {
			return true;
		}

		board[nextRow][nextCol] = 0;
	}

	return false;
}

vector<vector<char>> knightsTour(int startCol, int startRow) {
	vector<vector<char>> solution = vector<vector<char>>(8, vector<char>(8, 0));
	solution[startRow-1][startCol-1] = 1;
	backtrack(solution, startRow-1, startCol-1, 1);
	return solution;
}

vector<vector<char>> test() {
	return knightsTour(2, 1);
}

vector<vector<char>> run() {
	int x, y;
	cin >> x >> y;
	return knightsTour(x, y);
}

int main() {
	vector<vector<char>> solution = run();
	for (int i = 0; i < solution.size(); i++) {
		for (int j = 0; j < solution[i].size(); j++) {
			cout << (int)solution[i][j] << " ";
		}
		cout << "\n";
	}
}
