#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
		ListNode* head = l1->val > l2->val ? l1:l2;
		ListNode* p1 = l1, *p2 = l2;
		ListNode* p1_next, *p2_next;
		while(p1!=NULL && p2!=NULL){
			if(p1->val < p2->val){
				p1_next = p1->next;
				p1->next = p2;
				p1 = p1_next;
			}
			else{
				p2_next = p2->next;
				p2->next = p1;
				p2 = p2_next;
			}
		}
		return head;
	}
};

int main(){

	ListNode* head1 = new ListNode(0);
	ListNode* p1 = head1;
	p1->next = new ListNode(2);
	p1 = p1->next;
	p1->next = new ListNode(4);

	ListNode* head2 = new ListNode(1);
	ListNode* p2 = head2;
	p2->next = new ListNode(3);
	p2 = p2->next;
	p2->next = new ListNode(5);

	Solution sol;
	ListNode* new_head = sol.mergeTwoLists(head1, head2);

	ListNode* p = new_head;
	while(p){
		cout<<p->val<<" ";
		p = p->next; 
	}

}