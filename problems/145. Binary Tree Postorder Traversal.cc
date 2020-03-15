#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1{
public:
	vector<int> postorderTraversal(TreeNode* root){
		vector<int> traversal;
		if(!root) return traversal;
		helper(root->left, traversal);
		helper(root->right, traversal);
		traversal.push_back(root->val);
		return traversal;
	}
	void helper(TreeNode *node, vector<int> &traversal){
		if(!node) return;
		helper(node->left, traversal);
		helper(node->right, traversal);
		traversal.push_back(node->val);
	}
};

class Solution2{
public:
	vector<int> postorderTraversal(TreeNode* root){
		vector<int> traversal;
		if(!root) return traversal;
		stack<TreeNode*> ss;
		ss.push(root);
		TreeNode *cur;
		while(!ss.empty()){
			cur = ss.top();
			if(isValid(cur->left) || (isValid(cur->right))){
				if(isValid(cur->right)) ss.push(cur->right);
				if(isValid(cur->left)) ss.push(cur->left);
			} else {
				traversal.push_back(cur->val);
				traversed.insert(cur);
				ss.pop();
			}
		}
		return traversal;
	}
private:
	set<TreeNode*> traversed;
	bool isValid(TreeNode *node){
		return node && (traversed.count(node) == 0);
	}
};

int main(){
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
	vector<int> res = sol.postorderTraversal(N1);

	for(int i=0; i<res.size(); i++){
		cout << res[i] << " ";
	}
}