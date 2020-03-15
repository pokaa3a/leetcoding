#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if(!head) {return NULL;}
		if(!head->next) {return NULL;}

		ListNode *fast = head->next->next, *slow = head->next;
		while(fast != slow){
			if(!fast || !slow || !fast->next){
				return NULL;
			}
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *new_slow = head;
		while(new_slow != slow){
			new_slow = new_slow->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main() {
	ListNode *N0 = new ListNode(0);

	vector<ListNode*> nodes;
	nodes.push_back(new ListNode(0));
	for(int i=1; i<8; ++i) {
		nodes.push_back(new ListNode(i));
		nodes[i-1]->next = nodes[i];
	}
	nodes.back()->next = nodes[2];

	Solution sol;
	ListNode *res = sol.detectCycle(nodes[0]);
	if(res){
		cout << res->val << endl;
	} else {
		cout << "null" << endl;
	}

}