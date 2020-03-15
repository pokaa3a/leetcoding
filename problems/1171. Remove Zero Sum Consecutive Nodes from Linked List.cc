#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		unordered_map<int, ListNode*> m;
		unordered_map<ListNode*, int> m_inv;

		ListNode* cur = head;

		int cur_sum = 0;
		while (cur) {
			cur_sum += cur->val;
			
			if (m.find(cur_sum) != m.end()) {
				ListNode* sub_cur = m[cur_sum]->next;
				while (sub_cur != cur->next) {
					m.erase(m_inv[sub_cur]);
					sub_cur = sub_cur->next;
				}
				m[cur_sum]->next = cur->next;
			} else if (cur_sum == 0) {
				ListNode* sub_cur = head;
				while (sub_cur != cur->next) {
					m.erase(m_inv[sub_cur]);
					sub_cur = sub_cur->next;
				}
				head = cur->next;
			} else {
				m[cur_sum] = cur;
				m_inv[cur] = cur_sum;
			}
			cur = cur->next;
		}
		return head;
	}
};

int main() {
	ListNode* n1 = new ListNode(0);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(-3);
	ListNode* n5 = new ListNode(1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution sol;
	ListNode* head = sol.removeZeroSumSublists(n1);
	ListNode* cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;

}