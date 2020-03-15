#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root){
		if(!root) return true;
		return isValidSubBST(root, double(INT_MAX)+1, double(INT_MIN)-1);
	}

	bool isValidSubBST(TreeNode* root, double ceil, double floor){

		if(!root) return true;

		if(root->left && (!(root->left->val > floor) || !(root->left->val < ceil))) return false;
		if(root->right && (!(root->right->val > floor) || !(root->right->val < ceil))) return false;
		if(root->left && !(root->left->val < root->val)) return false;
		if(root->right && !(root->right->val > root->val)) return false;

		return isValidSubBST(root->left, root->val, floor) && isValidSubBST(root->right, ceil, root->val);
	}
};


int main(){

	TreeNode* n0 = new TreeNode(2);
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(3);
	// TreeNode* n3 = new TreeNode(12);
	// TreeNode* n4 = new TreeNode(20);

	n0->left = n1;
	n0->right = n2;
	// n2->left = n3;
	// n2->right = n4;

	Solution sol;
	cout<<sol.isValidBST(n0);

}