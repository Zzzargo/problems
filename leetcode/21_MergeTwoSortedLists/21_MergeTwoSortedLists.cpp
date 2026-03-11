#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (!list1) return list2;
    if (!list2) return list1;

	ListNode *sentinel = new ListNode();
	ListNode *tail = sentinel;

	while (list1 && list2) {
		if (list1->val <= list2->val) {
			tail->next = list1;
			list1 = list1->next;
		} else {
			tail->next = list2;
			list2 = list2->next;
		}

		tail = tail->next;
	}

	// Attach the remainder of the longer list
	tail->next = list1 ? list1 : list2;

	return sentinel->next;
}

int main() {
	ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
	// List1 = [1, 2, 4]
	cout << "List 1:\n[";
	ListNode *curr = list1;
	while (curr != nullptr) {
		cout << curr->val << ", ";
		curr = curr->next;
	}
	cout << "]" << endl;

	ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(5))));
	// List2 = [1, 3, 4, 5]
	cout << "List 2:\n[";
	curr = list2;
	while (curr != nullptr) {
		cout << curr->val << ", ";
		curr = curr->next;
	}
	cout << "]" << endl;

	ListNode *mergedSortedLists = mergeTwoLists(list1, list2);
	cout << "Merged list:\n[";
	curr = mergedSortedLists;
	while (curr != nullptr) {
		cout << curr->val << ", ";
		curr = curr->next;
	}
	cout << "]" << endl;

	return 0;
}
