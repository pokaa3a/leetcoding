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
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        dfs(root, INT_MAX, INT_MIN);
        return ans;
    }
private:
	int ans;
	void dfs(TreeNode* root, int mini, int maxi) {
		mini = min(mini, root->val);
		maxi = max(maxi, root->val);
		if (!root->left && !root->right) {
			ans = max(ans, abs(mini - maxi));
			return;
		}
		if (root->left) dfs(root->left, mini, maxi);
		if (root->right) dfs(root->right, mini, maxi);
	}
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}