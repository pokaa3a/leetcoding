#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		TreeNode *root = NULL;
		for (int i = 0; i < nums.size(); ++i) {
			root = addNode(root, nums[i]);
		}
		return root;
    }
	TreeNode* addNode(TreeNode* root, int x) {
		
		TreeNode *new_node = new TreeNode(x);
		TreeNode *new_root;

		if (!root) {
			new_root = new_node;
		} else {
			if (x > root->val) {
				new_node->left = root;
				new_root = new_node;
			} else {
				TreeNode* right_tree = addNode(root->right, x);
				root->right = right_tree;
				new_root = root;
			}
		}
		return new_root;
	}
};
*/

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	stack<TreeNode*> stk;
    	TreeNode *node = new TreeNode(nums[0]);
    	stk.push(node);
    	for (int i = 1; i < nums.size(); ++i) {
    		TreeNode *tmp = NULL;
    		while (!stk.empty() && stk.top()->val < nums[i]) {
    			stk.top()->right = tmp;
    			tmp = stk.top();
    			stk.pop();
    		}
    		TreeNode *new_node = new TreeNode(nums[i]);
    		new_node->left = tmp;
    		stk.push(new_node);
    	}

    	TreeNode *root = NULL;
    	while(!stk.empty()) {
    		stk.top()->right = root;
    		root = stk.top();
    		stk.pop();
    	}
    	return root;
    }
};

int main() {
	int array[] = {3, 2, 1, 6, 0, 5};
	vector<int> nums(array, array + 6);

	Solution sol;
	TreeNode* root = sol.constructMaximumBinaryTree(nums);
}