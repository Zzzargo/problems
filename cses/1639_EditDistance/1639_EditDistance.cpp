#include <algorithm>
#include <iostream>

using namespace std;

// Find the minimum of operations needed to transform a string s1 into another s2 (Edit distance, from now on ED)
int main() {
	string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    int n = s1.size();
    int m = s2.size();

	// dp(i)(j) = current state = minED to transform the first i elements of the first array into the first j elements
	// of the second array
    static int dp[5001][5001];

	// When either string is empty the ED is the length of the non-empty string
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
				// Characters match => zero cost added
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(
					dp[i - 1][j],  // Delete
					min(
						dp[i][j - 1],  // Add
						dp[i - 1][j - 1]  // Replace
					)
				);
            }
        }
    }

	// minED to transform the string s1(leb n) into the string s2(len m)
    cout << dp[n][m] << endl;
    return 0;
}
