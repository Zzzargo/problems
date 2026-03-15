#include <iostream>
#include <vector>

using namespace std;

/**
 * Doesn't really remove duplicates, just leaves them at the end and tells what's the real new length
*/
int removeDuplicates(vector<int>& nums) {
	if (nums.empty())
		return 0;

	size_t len = nums.size();
	int i = 0;
	for (int j = 1; j < len; j++) {
		if (nums[j] != nums[i]) {
			i++;
			nums[i] = nums[j];
		}
	}

	return i + 1;
}

int main() {
	vector<int> test = {1, 1, 2, 3, 4, 4, 5, 6, 6};

	cout << "Vector:\n[";
	for (int i : test) {
		cout << i << ", ";
	}
	cout << "], length = " << test.size() << endl;

	int newLen = removeDuplicates(test);
	cout << "Vector without duplicates:\n[";
	for (int i : test) {
		cout << i << ", ";
	}
	cout << "], length = " << test.size() << "(" << newLen << ")" << endl;

	return 0;
}
