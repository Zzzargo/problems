#include <bits/stdc++.h>
#include <climits>

using namespace std;

// https://cses.fi/problemset/task/1097/

int main() {
	int n;
	cin >> n;
	vector<int> scores(n);

	// We use the idea that scoreP1 + scoreP2 = sum(scores) => in order to maximize scoreP1 we need to minimize scoreP2
	// That means, at each step we want to maximize the difference between the two players' score
	// dp[i][j] = maximum score difference between the scores at indexes i and j
	vector<vector<long long>> dp(n, vector<long long>(n));
	long long totalSum = 0;

	// Initialization. For a subarray of one element the score difference is the value inside
	for (int i = 0; i < n; i++) {
		cin >> scores[i];
		dp[i][i] = scores[i];
		totalSum += scores[i];
	}

	for (int left = n - 1; left >= 0; left--) {
		for (int right = left + 1; right < n; right++) {
			// In the current window, either choose the first value and its difference with the rest of the window
			// Or the last value and the rest of the window
			long long takeFirstVal = scores[left] - dp[left+1][right];
			long long takeLastVal = scores[right] - dp[left][right - 1];
			dp[left][right] = max(takeFirstVal, takeLastVal);
		}
	}

	cout << (totalSum + dp[0][n-1]) / 2;

	return 0;
}
