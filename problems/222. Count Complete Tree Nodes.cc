#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode *root) {
		TreeNode *left = root, *right = root;

		int l = 0, r = 0;
		while(left) {
			left = left->left;
			l++;
		}
		while(right) {
			right = right->right;
			r++;
		}
		if (l == r) return pow(2, l) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

int main () {
	TreeNode *n1 = new TreeNode(1);
	// TreeNode *n2 = new TreeNode(2);
	// TreeNode *n3 = new TreeNode(3);
	// TreeNode *n4 = new TreeNode(4);
	// TreeNode *n5 = new TreeNode(5);
	// TreeNode *n6 = new TreeNode(6);

	// n1->left = n2;
	// n1->right = n3;
	// n2->left = n4;
	// n2->right = n5;
	// n3->left = n6;

	Solution sol;
	cout << sol.countNodes(n1);
}