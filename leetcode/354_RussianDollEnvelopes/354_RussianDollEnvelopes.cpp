#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/russian-doll-envelopes/

int maxEnvelopes(vector<vector<int>> &envelopes) {
	int n = envelopes.size();
    if (n == 0) return 0;

	// First sort the envelopes increasingly by width, and for equals widths - decreasingly by height
	// That optimizes the later search in the dp algorithm
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
		// Equal widhts => first the greater height
        if (a[0] == b[0]) return a[1] > b[1];
		// First the lesser width
        return a[0] < b[0];
    });

    // This is an adaptation of the LIS problem. Use lower_bound to search for greater widths if needed
	// This loop will be of (O(N log N))
	
	// tails[i] = the minimum height of last envelope in a solution which takes the first i + 1 envelopes
    vector<int> tails;
    for (int i = 0; i < n; i++) {
        int height = envelopes[i][1];
        
		// Binary search (O(log N))
        auto it = lower_bound(tails.begin(), tails.end(), height);
        
        if (it == tails.end()) {
			// Current height is the greatest among what we have in the current solution => add another envelope
            tails.push_back(height);
        } else {
			// Replace the last envelope with one with a bigger weight/height to fit more envelopes inside
            *it = height;
        }
    }

    return tails.size();
}

int main() {
	vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
	int sol = maxEnvelopes(envelopes);
	cout << sol << endl;
}
