#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head) return NULL;

		ListNode* extra_head = new ListNode(head->val - 1);
		extra_head->next = head;

		ListNode *pre = extra_head, *cur = head, *probe;
		while (cur) {
			probe = cur->next;
			while (probe) {
				if (cur->val != probe->val) {
					break;
				}
				probe = probe->next;
			}
			if (cur->next == probe) {	// no duplicates
				pre = pre->next;
				cur = cur->next;
			} else {					// detect duplicates
				cur = probe;
				pre->next = cur;
			}
		}
		return extra_head->next;
	}
};

int main(){
	ListNode* N0 = new ListNode(1);
	ListNode* N1 = new ListNode(2);
	ListNode* N2 = new ListNode(3);
	ListNode* N3 = new ListNode(3);
	ListNode* N4 = new ListNode(4);
	ListNode* N5 = new ListNode(4);
	ListNode* N6 = new ListNode(5);

	N0->next = N1;
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = N5;
	N5->next = N6;

	Solution sol;
	ListNode* head = sol.deleteDuplicates(N0);

	while(head) {
		std::cout << head->val << " ";
		head = head->next;
	}
}