#include <bits/stdc++.h>
#include <climits>

using namespace std;

// https://cses.fi/problemset/task/1744

// dp[i][j] = number of cuts needed to get a rectangle of size i,j to all squares
int dp[501][501];

// O(a*b*(a+b)) (O(n^3))
int main() {
	int a, b;  // Rectangle width, height

	cin >> a >> b;

	for (int w = 0; w <= a; w++) {
		for (int h = 0; h <= b; h++) {
			dp[w][h] = 1e9;  // using INT_MAX would have produced an overflow in the algorithm
			if (w == h)
				dp[w][h] = 0;  // It takes 0 cuts to turn a rectangle of equal width and height into a square
		}
	}

	for (int w = 1; w <= a; w++) {
		for (int h = 1; h <= b; h++) {
			// Try all possible cuts for the current dimension and update the dp matrix
			for (int horizCut = 1; horizCut < a; horizCut++) {
				dp[w][h] = min(dp[w][h], dp[horizCut][h] + dp[w - horizCut][h] + 1);
			}

			for (int vertCut = 1; vertCut < b; vertCut++) {
				dp[w][h] = min(dp[w][h], dp[w][vertCut] + dp[w][h - vertCut] + 1);
			}
		}
	}

	cout << dp[a][b];

	return 0;
}
