#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode *head) {
		// add a dummy node at the begging
		ListNode *dummy = new ListNode(INT_MIN);
		dummy->next = head;
		head = dummy;

		ListNode *sorted_end = head;
		while (sorted_end->next) {
			ListNode *to_be_inserted = find_to_insert(head, sorted_end);
			ListNode *to_insert = sorted_end->next;
			sorted_end->next = to_insert->next;
			to_insert->next = to_be_inserted->next;
			to_be_inserted->next = to_insert;
			if (to_be_inserted == sorted_end) sorted_end = sorted_end->next;
		}
		return head->next;
	}

	ListNode* find_to_insert(ListNode *head, ListNode *sorted_end) {
		ListNode *current = head;
		while (current != sorted_end) {
			if (current->next->val > sorted_end->next->val) {
				return current;
			}
			current = current->next;
		}
		return current;
	}
};

int main() {
	ListNode *p1 = new ListNode(-1);
	ListNode *p2 = new ListNode(5); p1->next = p2;
	ListNode *p3 = new ListNode(3); p2->next = p3;
	ListNode *p4 = new ListNode(4); p3->next = p4;
	ListNode *p5 = new ListNode(0); p4->next = p5;
	Solution sol;
	ListNode *head = sol.insertionSortList(p1);
	ListNode *cur = head;
	while (cur) {
		cout << cur->val << endl;
		cur = cur->next;
	}
}


