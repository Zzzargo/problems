#include <fstream>
#include <iostream>

using namespace std;

// https://www.pbinfo.ro/probleme/2528/lungimesubsircomunmaximal/

/**
 * This problem can be solved with dynamic programming (DP from now on)
 * Define dp[i][j] the problem state = the longest common substring up to and including the i-th index in the
 * first string and the j-th index in the second string
 * s1.len <= 1000; s2.len <= 1000
*/

short longestCommonSubstring(string s1, string s2) {
	short dp[1001][1001];
}

int main() {
	ifstream fin("lungimesubsircomunmaximal.in");
	ofstream fout("lungimesubsircomunmaximal.out");

	string s1, s2;
	fin >> s1 >> s2;
	fout << longestCommonSubstring(s1, s2);

	return 0;
}
