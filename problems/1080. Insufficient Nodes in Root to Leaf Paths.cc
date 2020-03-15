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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (isSufficient(root, 0, limit)) return root;
        return NULL;
    }
    bool isSufficient(TreeNode* root, int sums, int limit) {
    	if (!root->left && !root->right) {
    		return sums + root->val < limit ? false : true;
    	}
    	bool lft = false;
    	if (root->left && isSufficient(root->left, sums + root->val, limit)) lft = true;
    	else root->left = NULL;

    	bool rht = false;
    	if (root->right && isSufficient(root->right, sums + root->val, limit)) rht = true; 
    	else root->right = NULL;

    	return lft | rht;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}