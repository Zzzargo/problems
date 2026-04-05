#include <bits/stdc++.h>

using namespace std;

// Check if a slice of the original string s, s[from...to] is a palindrome
bool isPalindrome(string s, int from, int to) {
	while (from < to) {
		if (s[from++] != s[to--])
			return false;
	}
	return true;
}

void backtrack(string &s, int start, vector<string> &partition, vector<vector<string>> &res) {
	int len = s.length();
	if (start == len) {
		// Found a new partition
		res.push_back(partition);
		return;
	}

	for (int i = start; i < len; i++) {
		if (isPalindrome(s, start, i)) {
			// Try to include this slice in a partition
			partition.push_back(s.substr(start, i - start + 1));

			// Continue solving for this partition
			backtrack(s, i + 1, partition, res);

			// Remove the current slice to try others
			partition.pop_back();
		}
	}
}

// s only contains lowercase English letters
vector<vector<string>> partition(string s) {
	vector<vector<string>> solution;
	vector<string> path;
	backtrack(s, 0, path, solution);
	return solution;
}

int main() {
	string s = "aab";
	vector<vector<string>> solution = partition(s);

	for (int i = 0; i < solution.size(); i++) {
		cout << "[";
		for (int j = 0; j < solution[i].size(); j++) {
			cout << solution[i][j] << ", ";
		}
		cout << "]\n";
	}
}
