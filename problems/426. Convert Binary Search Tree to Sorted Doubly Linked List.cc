#include <iostream>
#include <set>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}
	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if (!root) return NULL;

		pair<Node*, Node*> list = treeToSingleList(root);
		list.first->left = list.second;
		list.second->right = list.first;
		return list.first;
	}
	pair<Node*, Node*> treeToSingleList(Node* root) {
		Node* first;
		Node* last;
		if (root->left) {
			pair<Node*, Node*> left_list = treeToSingleList(root->left);
			first = left_list.first;
			left_list.second->right = root;
			root->left = left_list.second;
		} else {
			first = root;
		}

		if (root->right) {
			pair<Node*, Node*> right_list = treeToSingleList(root->right);
			last = right_list.second;
			right_list.first->left = root;
			root->right = right_list.first;
		} else {
			last = root;
		}
		return make_pair(first, last);
	}
};

int main() {
	Node* n1 = new Node(1, NULL, NULL);
	Node* n2 = new Node(2, NULL, NULL);
	Node* n3 = new Node(3, NULL, NULL);
	Node* n4 = new Node(4, NULL, NULL);
	Node* n5 = new Node(5, NULL, NULL);

	n4->left = n2;
	n4->right = n5;
	n2->left = n1;
	n2->right = n3;

	Solution sol;
	Node* root = sol.treeToDoublyList(n4);

	set<int> visited;
	Node* p = root;
	while (!visited.count(p->val)) {
		visited.insert(p->val);
		cout << p->val << " ";
		p = p->right;
	}
}