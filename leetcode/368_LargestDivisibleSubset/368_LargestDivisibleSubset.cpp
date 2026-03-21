#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
	if (nums.empty())
		return {};

	// O(N^2) overall

	// First, sort the original vector to easily find increasingly divisible numbers
	sort(nums.begin(), nums.end());

	int n = nums.size();
	// dp[i] = length of the largest divisible subset with the first i numbers from the original vector
	vector<int> dp(n, 1);
	// Vector to reconstruct the solution
    vector<int> parent(n, -1);  // -1 indicates that a number doesn't have a parent in the solution tree
    int maxIdx = 0;

    // DP Algorithm (O(n^2))
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        // Remember where the max len subset ends
        if (dp[i] > dp[maxIdx]) {
            maxIdx = i;
        }
    }

    // Rebuild the solution
    vector<int> result;
    int curr = maxIdx;
    while (curr != -1) {
		// The first element in the solution subset is at parent -1
		// The order however doesn't really matter
        result.push_back(nums[curr]);
        curr = parent[curr];
    }

    return result;
}

int main() {
	vector<int> nums = {1, 2, 4, 8};

	auto res = largestDivisibleSubset(nums);

	cout << "Solution: \n[";
	for (int num : res) {
		cout << num << ", ";
	}
	cout << "]" << endl;

	return 0;
}
