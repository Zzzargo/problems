#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
#include <vector>

using namespace std;

void backtrack(vector<int> &candidates, int target, int idx, vector<int> &variant, vector<vector<int>> &solution) {
	if (target == 0) {
		// This call found a sequence with the target sum
		solution.push_back(variant);
		return;
	}

	for (int i = idx; i < candidates.size(); i++) {
		// Pruning: if the current number is too big for the sum in construction leave this solution
		if (candidates[i] > target)
			break;

		// Pruning: don't allow duplicates. Since the candidates are sorted this can be done by checking the prev
		if (i > idx && candidates[i] == candidates[i-1])
			continue;

		// The actual variant building: add the current candidate
		variant.push_back(candidates[i]);

		// See if the variant is ok and if not try to add another candidate
		backtrack(candidates, target - candidates[i], i + 1, variant, solution);

		// Backtrack
		variant.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int >&candidates, int target) {
	// A massive pruning can be achieved by sorting the candidates, so duplicates are easily found
	// And a variant can be aborted for an initial number if the sum exceeds the target
	sort(candidates.begin(), candidates.end());

	vector<vector<int>> solution;
	vector<int> variant;

	backtrack(candidates, target, 0, variant, solution);

	return solution;
}

int main() {
	/*
	 * candidates = [10,1,2,7,6,1,5], target = 8
	 * Output:
	 * [
	 *	[1,1,6],
	 *	[1,2,5],
	 *	[1,7],
	 *	[2,6]
	 * ]
	*/
	vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
	int target = 8;

	vector<vector<int>> solution = combinationSum2(candidates, target);

	cout << "Solution:\n[\n";
	for (int i = 0; i < solution.size(); i++) {
		cout << "	[";
		for (int j = 0; j < solution[i].size(); j++) {
			cout << solution[i][j] << ", ";
		}
		cout << "],\n";
	}
	cout << "]" << endl;
}
