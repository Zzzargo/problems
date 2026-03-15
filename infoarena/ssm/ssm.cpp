#include <climits>
#include <fstream>
#include <iostream>

using namespace std;

// https://infoarena.ro/problema/ssm
// Finding the substring with the max sum

int main() {
	ifstream fin("ssm.in");
	ofstream fout("ssm.out");

	int n, x, sum = 0, left = 1, tempLeft = left, right, max = INT_MIN;
	fin >> n;
	for (int i = 1; i <= n; i++) {
		fin >> x;

		sum += x;
		if (sum > max) {
			max = sum;
			left = tempLeft;
			right = i;
		}

		if (sum < 0) {
			sum = 0;
			tempLeft = i + 1;
		}
	}

	fout << max << " " << left << " " << right;

	return 0;
}
