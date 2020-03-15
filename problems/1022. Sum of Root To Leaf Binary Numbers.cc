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
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
private:
	int ans;
	void dfs(TreeNode* root, int x) {
		x = 2 * x + root->val;
		if (!root->left && !root->right) ans += x;
		if (root->left) dfs(root->left, x);
		if (root->right) dfs(root->right, x);
	}
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}