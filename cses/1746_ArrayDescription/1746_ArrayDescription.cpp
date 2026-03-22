#include <bits/stdc++.h>

using namespace std;

int arrayDescription(vector<int> nums, int n, int m) {
	// dp[i][j] = number of ways to fill an array of i numbers, such that the value at index i is j
	// To have the value j at position i, the value at i-1 must be j, j-1 or j+1
	// We use m + 2 to avoid checking (j-1 >= 1) and (j+1 <= m) every time
	vector<vector<int>> dp(n, vector<int>(m + 2, 0));

	const int MOD = 1e9 + 7;

	// Base Case: First element
    if (nums[0] == 0) {
        // If unknown, it could be anything from 1 to m
        for (int j = 1; j <= m; j++)
			dp[0][j] = 1;
    } else {
        // If known, only that value is possible
        dp[0][nums[0]] = 1;
    }

    // Fill the DP table. Overall time complexity: O(n * m)
    for (int i = 1; i < n; i++) {
        if (nums[i] == 0) {
            // Unknown: try every possible value j
            for (int j = 1; j <= m; j++) {
                long long sum = (long long)dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] = sum % MOD;
            }
        } else {
            // Known: only calculate for nums[i]
            int j = nums[i];
            long long sum = (long long)dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            dp[i][j] = sum % MOD;
        }
    }

    // Final Result: Sum of all possibilities at the last index
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[n-1][j]) % MOD;
    }

	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for (int i = 0; i < n ; i++)
		cin >> nums[i];

	cout << arrayDescription(nums, n, m);
	return 0;
}
