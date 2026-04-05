#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
	int minimumIndex(vector<int>& capacity, int itemSize) {
		int minIdx = -1;
		int minCap = INT_MAX;
		int len = capacity.size();
		for (int i = 0; i < len; i++) {
			if (capacity[i] < minCap && capacity[i] >= itemSize) {
				minIdx = i;
				minCap = capacity[i];
			}
		}
		return minIdx;
	}
};

int main() {
	Solution x;
	vector<int> capacities = {3, 5, 4, 3};
	cout << x.minimumIndex(capacities, 2) << endl;
}
