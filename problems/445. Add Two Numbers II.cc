#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2;
		stack<int> s1, s2;

		while (p1) {
			s1.push(p1->val);
			p1 = p1->next;
		}

		while (p2 != NULL) {
			s2.push(p2->val);
			p2 = p2->next;
		}

		ListNode *cur = NULL, *old = NULL;
		int carry = 0;
		while (!s1.empty() || !s2.empty() || carry) {
			int n1 = s1.empty() ? 0 : s1.top();
			int n2 = s2.empty() ? 0 : s2.top();
			cur = new ListNode((n1 + n2 + carry) % 10);
			cur->next = old;
			old = cur;
			carry = (n1 + n2 + carry) / 10;
			if (!s1.empty()) s1.pop();
			if (!s2.empty()) s2.pop();
		}
		if (!cur) return new ListNode(0);
		return cur;
	}
};

int main() {
	unsigned long int num1 = 5;
	unsigned long int num2 = 5;

	ListNode *l1, *old1 = NULL, *l2, *old2 = NULL;
	while (num1 > 0) {
		l1 = new ListNode(num1 % 10);
		l1->next = old1;
		num1 /= 10;
		old1 = l1;
	}
	while (num2 > 0) {
		l2 = new ListNode(num2 % 10);
		l2->next = old2;
		num2 /= 10;
		old2 = l2;
	}

	// ListNode *p1 = l1, *p2 = l2;
	// while (p2) {
	// 	cout << p2->val << " ";
	// 	p2 = p2->next;
	// }

	Solution sol;
	ListNode* head = sol.addTwoNumbers(l1, l2);

	ListNode *p = head;
	while (p) {
		cout << p->val;
		p = p->next;
	}
}