#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		TreeNode *cur = root;
		while (cur) {
			s.push(cur);
			cur = cur->left;
		}
	}

	bool hasNext() {
		return !s.empty();
	}

	int next() {
		if (hasNext()) {
			TreeNode *node = s.top();
			s.pop();

			TreeNode *cur = node->right;
			while (cur) {
				s.push(cur);
				cur = cur->left;
			}
			return node->val;
		}
		return 0;
	}
private:
	stack<TreeNode*> s;
};

int main() {

	TreeNode *N0 = new TreeNode(0);
	TreeNode *N1 = new TreeNode(1);
	TreeNode *N2 = new TreeNode(2);
	TreeNode *N3 = new TreeNode(3);
	TreeNode *N4 = new TreeNode(4);
	TreeNode *N5 = new TreeNode(5);

	N3->left = N1;
	N1->left = N0;
	N1->right = N2;
	N3->right = N5;
	N5->left = N4;

	BSTIterator i = BSTIterator(N3);
	while (i.hasNext()) cout << i.next();
}