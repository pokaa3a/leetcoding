#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
     	go_through(root, 0);
     	return root;
    }
    int go_through(TreeNode* root, int sums) {
    	int val = root->val;
    	int rht_sums = 0;
    	if (root->right) rht_sums = go_through(root->right, sums);
    	root->val += sums + rht_sums;
    	int lft_sums = 0;
    	if (root->left) lft_sums = go_through(root->left, root->val);
    	return val + rht_sums + lft_sums;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}