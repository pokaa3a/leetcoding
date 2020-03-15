#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode *head){
		if(!head || !head->next) return head;
		ListNode *middle_node = findMideleNode(head);
		ListNode *head2 = middle_node->next;
		middle_node->next = NULL;
		return merge(sortList(head), sortList(head2));
	}

	ListNode* merge(ListNode *head1, ListNode *head2){
		ListNode *cur1 = head1, *cur2 = head2;
		ListNode *dummy = new ListNode(0);
		ListNode *node = dummy;
		while(cur1 && cur2){
			if(cur1->val < cur2->val){
				node->next = cur1;
				cur1 = cur1->next;
			} else {
				node->next = cur2;
				cur2 = cur2->next;
			}
			node = node->next;
		}
		node->next = cur1 ? cur1 : cur2;
		return dummy->next;
	}

	ListNode* findMideleNode(ListNode *head){
		if(!head->next) return head;
		ListNode *fast = head, *slow = head;
		while(fast && fast->next && fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main() {
	ListNode *N0 = new ListNode(-1);
	ListNode *N1 = new ListNode(5);
	ListNode *N2 = new ListNode(3);
	ListNode *N3 = new ListNode(4);
	ListNode *N4 = new ListNode(0);

	N0->next = N1;
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;

	Solution sol;
	ListNode *head = sol.sortList(N0);

	ListNode *cur = head;
	while(cur){
		cout << cur->val << " ";
		cur = cur->next;
	}

}