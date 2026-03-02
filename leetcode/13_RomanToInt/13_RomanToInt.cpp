#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

// This bad boi gets me to 0ms
inline static constexpr int romanCharToInt(char c) {
	switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return -1;
	}
}

int romanToInt(string s) {
	size_t len = s.length();
	int num = 0;

	for (size_t i = 0; i < len; i++) {
		if (i != len - 1 && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
			num -= romanCharToInt(s[i]);
		} else {
			num += romanCharToInt(s[i]);
		}
	}

	return num;
}

int main() {
	string romanNum = "XLVII";
	cout << romanNum << " = " << romanToInt(romanNum) << endl;
}
