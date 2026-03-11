#include <iostream>
#include <stack>

using namespace std;

inline static constexpr bool isOpener(char s) {
	return s == '(' || s == '[' || s == '{';
}

inline static constexpr char getCorrespondent(char s) {
	switch (s) {
		case ')':
			return '(';
		case ']':
			return '[';
		case '}':
			return '{';
		default:
			return '\0';
	}
}

bool isValid(string s) {
	stack<char> buddy;

	for (char c : s) {
		if (isOpener(c)) {
			buddy.push(c);
		} else {
			if (buddy.empty() || getCorrespondent(c) != buddy.top()) {
				return false;
			}
			buddy.pop();
		}
	}
	return buddy.empty();
}

int main() {
	string yoGurt = "({})[]";
	cout << "The string " << yoGurt << (isValid(yoGurt) ? " is " : " is not ") << "valid" << endl;
}
