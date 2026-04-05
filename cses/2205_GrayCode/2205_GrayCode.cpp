#include <bits/stdc++.h>
#include <bitset>

using namespace std;

// n <= 16
vector<bitset<16>> grayCode(int n) {
	// Gray code is also known as `binary reflected code`. A way of translating binary to Gray is
	// gray_i = binary_i ^ (binary_i >> 1)
	int numNums = 1 << n;
	vector<bitset<16>> solution(numNums);

	for (int i = 0; i < numNums; i++) {
		int gray = i ^ (i >> 1);
		solution[i] = bitset<16>(gray);
	}

	return solution;
}

int main() {
	int n;
	cin >> n;

	vector<bitset<16>> solution = grayCode(n);

	for (int i = 0; i < solution.size(); i++) {
		cout << solution[i].to_string().substr(16 - n) << "\n";
	}
}
