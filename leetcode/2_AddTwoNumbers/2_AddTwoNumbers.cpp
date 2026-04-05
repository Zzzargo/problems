#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		bool carry = 0;
		ListNode *sumHead = NULL;
		ListNode *curr = NULL;

		while (l1 || l2 || carry) {
			int x1 = 0, x2 = 0;
			if (l1 != NULL)
				x1 = l1->val;
			if (l2 != NULL)
				x2 = l2->val;

			// Sum + carry calculation
			int currSum = x1 + x2 + carry;
			if (currSum > 9) {
				currSum %= 10;
				carry = 1;
			} else {
				carry = 0;
			}

			if (sumHead == NULL) {
				sumHead = new ListNode(currSum);
				curr = sumHead;
			} else {
				curr->next = new ListNode(currSum);
				curr = curr->next;
			}

			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		return sumHead;
    }
};

int main() {
	// 9999999 + 9999 = 89990001 (10009998)
	ListNode *num1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
	ListNode *num2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
	Solution sol;
	ListNode *sum = sol.addTwoNumbers(num1, num2);
	
	cout << "Sum: [";
	while (sum != NULL) {
		cout << sum->val << ", ";
		sum = sum->next;
	}
	cout << "]" << endl;
}
