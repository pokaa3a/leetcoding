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
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
	int ans;
    int longestZigZag(TreeNode* root) {
        ans = 0;
        dfs(root);

        return ans;
    }
    pair<int, int> dfs(TreeNode* root) {
    	if (!root) {
    		return make_pair(-1, -1);
    	}

    	pair<int, int> p_l = dfs(root->left);
    	pair<int, int> p_r = dfs(root->right);
    	int left = p_l.second + 1;
    	int right = p_r.first + 1;
    	ans = max(ans, max(left, right));

    	return make_pair(left, right);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n = 8;
	vector<TreeNode*> v(n);
	for (int i = 0; i < n; ++i) v[i] = new TreeNode(1);

	v[0]->right = v[1];
	v[1]->left = v[2];
	v[1]->right = v[3];
	v[3]->left = v[4];
	v[3]->right = v[5];
	v[4]->right = v[6];
	v[6]->right = v[7];

	cout << sol.longestZigZag(v[0]) << endl;

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}