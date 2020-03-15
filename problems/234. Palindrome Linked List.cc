#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
	ListNode* tmp;
	bool isPalindrome(ListNode* head){
		tmp = head;
		return check(head);
	}

	bool check(ListNode* p){
		if(p==NULL) return true;
		bool isPal = check(p->next) & (tmp->val==p->val);
		tmp = tmp->next;
		return isPal;
	}
};

int main(){
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	p->next = new ListNode(1);
	p = p->next;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(1);
	p = p->next;
	p->next = new ListNode(0);

	Solution sol;
	cout<<sol.isPalindrome(head);
}