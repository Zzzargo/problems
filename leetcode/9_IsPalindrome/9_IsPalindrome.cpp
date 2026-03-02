#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

	// Start with the digits on either side and work your way up to the middle
	int reversedHalf = 0;
	while (x > reversedHalf) {
		reversedHalf = reversedHalf * 10 + x % 10;
		x /= 10;
	}

    return x == reversedHalf || x == reversedHalf / 10;
}

int main() {
    cout << "-121: " << isPalindrome(-121) << "\n2442: " << isPalindrome(2442) << endl;
    return 0;
}
