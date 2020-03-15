#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		int l = height(root->left);
		int r = height(root->right);
		if (l != r) {
			if (l > r) return lcaDeepestLeaves(root->left);
			else return lcaDeepestLeaves(root->right);
		}
		return root;
	}
private:
	int height(TreeNode* root) {
		if (!root) return 0;
		return 1 + max(height(root->left), height(root->right));
	}
};

class Solution {
private:
    TreeNode* ans;
    int deepest_leaves;
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        deepest_leaves = 0;
        dfs(root, 0);
        return ans;
    }
    int dfs(TreeNode* root, int this_depth) {
        if (!root->left && !root->right) {
            if (this_depth > deepest_leaves) {
                deepest_leaves = this_depth;
                ans = root;
            }
            return this_depth;
        }
        int lft_depth = this_depth;
        if (root->left) lft_depth = dfs(root->left, this_depth + 1);
        int rht_depth = this_depth;
        if (root->right) rht_depth = dfs(root->right, this_depth + 1);
        
        if (lft_depth == rht_depth) {
            if (lft_depth >= deepest_leaves) {
                ans = root;
            }
        }
        return max(lft_depth, rht_depth);
    }
};

void dfs(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	dfs(root->left);
	dfs(root->right);
};

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	n1->left = n2;
	n2->left = n3;
	n2->right = n4;
	n3->right = n6;
	n4->right = n5;
	Solution sol;
	TreeNode* n = sol.lcaDeepestLeaves(n1);
	dfs(n);
}