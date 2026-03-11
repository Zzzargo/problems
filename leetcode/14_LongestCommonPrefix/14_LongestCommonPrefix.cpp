#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	if (strs.empty())
		return "";

	// Checking each word depth-first => starting with the first word as the lcp
	string lcp = strs.front();
	size_t longestLength = lcp.size();

	size_t vecLen = strs.size();

	for (size_t i = 1; i < vecLen; i++) {
		if (strs[i].empty())
			return "";

		size_t currStrLen = strs[i].size();
		// Cap the length on shorter words
		if (currStrLen < longestLength)
			longestLength = currStrLen;

		for (size_t j = 0; j < currStrLen && j < longestLength; j++) {
			// Check each word with the current lcp
			if (strs[i][j] != lcp[j]) {
				longestLength = j;
				break;
			}
		}

		if (longestLength == 0)
			return "";
	}

	return lcp.substr(0, longestLength);
}

int main() {
	vector<string> strs = {"ab", "a"};
	cout << "Longest common prefix of [ ";
	for (string str : strs) {
		cout << str << ", ";
	}
	cout << "] = " << longestCommonPrefix(strs) << endl;
}
