#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1{
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int> traversal;
		if(!root) return traversal;

		traversal.push_back(root->val);
		helper(root->left, traversal);
		helper(root->right, traversal);
		return traversal;
	}
	void helper(TreeNode* node, vector<int> &traversal){
		if(!node) return;
		traversal.push_back(node->val);
		helper(node->left, traversal);
		helper(node->right, traversal);
	}
};

class Solution2{
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int> traversal;
		stack<TreeNode*> s;
		s.push(NULL);
		if(!root) return traversal;
		TreeNode *cur = root;
		while(cur && !s.empty()){
			traversal.push_back(cur->val);
			if(cur->right){
				s.push(cur->right);
			}
			if(cur->left){
				cur = cur->left;
			} else {
				cur = s.top();
				s.pop();
			}
		}
		return traversal;
	}
};

int main() {
	TreeNode *N1 = new TreeNode(1);
	TreeNode *N2 = new TreeNode(2);
	TreeNode *N3 = new TreeNode(3);
	TreeNode *N4 = new TreeNode(4);
	TreeNode *N5 = new TreeNode(5);
	TreeNode *N6 = new TreeNode(6);
	TreeNode *N7 = new TreeNode(7);
	N1->left = N2;
	N1->right = N3;
	N2->left = N4;
	N2->right = N5;
	N3->left = N6;
	N3->right = N7;

	Solution2 sol;
	vector<int> res = sol.preorderTraversal(N1);

	for(int i=0; i<res.size(); i++){
		cout << res[i] << " ";
	}
}