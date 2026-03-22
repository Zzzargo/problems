#include <bits/stdc++.h>

using namespace std;

int checkRecord(int n) {
	// limits: dp[n+1][2][3]. All values are initialized with 0
	// dp[i][j][k] = number of records of length i with j total absences and k consecutive late arrivals for the student
	// to receive the attendace award
	vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3, 0)));
	const int MOD = 1e9 + 7;

	// Inital state
	dp[0][0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int abs = 0; abs < 2; abs++) {
			for (int late = 0; late < 3; late++) {
				if (dp[i][abs][late] == 0)
					// Nothing can be done with this branch
					continue;

				// The idea behind this DP algorithm is to try all 3 presence types at each index i to see if it works
				long long currVal = dp[i][abs][late];

				// First the always compatible choice (and recommended, fellow students :) ) - to be present
				// This resets the consecutive late presences => index at 0 lateness
				dp[i+1][abs][0] = (currVal + dp[i+1][abs][0]) % MOD;

				// If the student can be late - do it
				if (late < 2)
					dp[i+1][abs][late + 1] = (currVal + dp[i+1][abs][late+1]) % MOD;

				// If an absence can be made increase the possibilities number
				if (abs < 1)
					dp[i+1][abs+1][0] = (currVal + dp[i+1][abs+1][0]) % MOD;
			}
		}
	}

	// The final answer is the sum of all valid choices for length n
	long long sum = 0;
	for (int abs = 0; abs < 2; abs++) {
		for (int late = 0; late < 3; late++) {
			sum = (sum + dp[n][abs][late]) % MOD;
		}
	}

	return (int)sum;
}

int main() {
	cout << checkRecord(2);
	return 0;
}
