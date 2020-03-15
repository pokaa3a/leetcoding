#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node *prev;
	Node *next;
	Node *child;

	Node() {}
	Node(int _val) {
		val = _val;
		prev = NULL;
		next = NULL;
		child = NULL;
	} 
	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	Node* flatten(Node* head) {
		if (!head) return NULL;
		Node* cur = head;
		while (cur->next) {
			Node* next = cur->next;
			if (cur->child) {
				Node* children_end = flatten_end(cur->child);
				cur->next = cur->child;
				cur->child->prev = cur;
				children_end->next = next;
				next->prev = children_end;
				cur->child = NULL;
			}
			cur = next;
		}
		if (cur->child) {
			cur->next = flatten(cur->child);
			cur->child->prev = cur;
			cur->child = NULL;
		}
		return head;
	}
private:
	Node* flatten_end(Node* head) {
		Node* cur = head;
		while (cur->next) {
			Node* next = cur->next;
			if (cur->child) {
				Node* children_end = flatten_end(cur->child);
				cur->next = cur->child;
				cur->child->prev = cur;
				children_end->next = next;
				next->prev = children_end;
				cur->child = NULL;
			}
			cur = next;
		}
		if (cur->child) {
			cur->next = cur->child;
			cur->child->prev = cur;
			Node* children_end = flatten_end(cur->child);
			cur->child = NULL;
			return children_end;
		}
		return cur;
	}
};


int main() {
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n8 = new Node(8);
	Node* n9 = new Node(9);
	Node* n10 = new Node(10);
	Node* n11 = new Node(11);
	Node* n12 = new Node(12);

	n1->next = n2;
	n2->prev = n1;
	n2->next = n3;
	n3->prev = n2;
	n3->next = n4;
	n4->prev = n3;
	n4->next = n5;
	n5->prev = n4;
	n5->next = n6;
	n6->prev = n5;
	n6->next = NULL;
	n3->child = n7;
	n7->next = n8;
	n8->prev = n7;
	n8->next = n9;
	n9->prev = n8;
	n9->next = n10;
	n10->prev = n9;
	n10->next = NULL;
	n8->child = n11;
	n11->next = n12;
	n12->prev = n11;
	n12->next = NULL;

	Solution sol;
	Node* head = sol.flatten(n1);
	Node* cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
}
