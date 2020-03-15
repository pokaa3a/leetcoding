#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	int maxPathSum(TreeNode* root){
		if(!root) return 0;
		int maxPath = INT_MIN;
		maxPathSumHelper(root, maxPath);
		return maxPath;
	}

	int maxPathSumHelper(TreeNode* root, int &maxPath){
		if(!root) return 0;
		int left = root->val + maxPathSumHelper(root->left, maxPath);
		int right = root->val + maxPathSumHelper(root->right, maxPath);
		maxPath = max( max(left, right), max(root->val, max(maxPath, left + right - root->val)));
		return max(max(left, right), root->val);
	}

};

int main(){
	TreeNode *N0 = new TreeNode(-10);
	TreeNode *N1 = new TreeNode(9);
	TreeNode *N2 = new TreeNode(20);
	TreeNode *N3 = new TreeNode(15);
	TreeNode *N4 = new TreeNode(7);

	N0->left = N1;
	N0->right = N2;
	N2->left = N3;
	N2->right = N4;

	Solution sol;
	cout << sol.maxPathSum(N0) << endl;
}