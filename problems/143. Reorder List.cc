#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	void reorderList(ListNode* head){
		if(!head || !head->next || !head->next->next) return;
		// Traverse the list and save each node into queue
		stack<ListNode*> myStack;
		ListNode *cur = head;
		while(cur){
			myStack.push(cur);
			cur = cur->next;
		}

		ListNode *p1 = head, *p2 = head->next, *p3 = myStack.top();
		myStack.pop();
		while(p1 != p3 && p2 != p3){
			p1->next = p3;
			p3->next = p2;
			p1 = p2;
			p2 = p2->next;
			p3 = myStack.top();
			myStack.pop();
		}
		if(p1 == p3) p1->next = NULL;
		if(p2 == p3) p2->next = NULL;
	}
};

int main(){
	ListNode *N0 = new ListNode(1);
	ListNode *N1 = new ListNode(2);
	ListNode *N2 = new ListNode(3);
	ListNode *N3 = new ListNode(4);
	ListNode *N4 = new ListNode(5);

	N0->next = N1;
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;

	Solution sol;
	sol.reorderList(N0);

	ListNode *node = N0;
	while(node){
		cout << node->val << " ";
		node = node->next;
	}
}