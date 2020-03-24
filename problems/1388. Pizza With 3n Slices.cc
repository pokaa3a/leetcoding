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
    int maxSizeSlices(vector<int>& slices) {
    	int n = slices.size();
    	return max(maxSizeSlices(0, n - 2, slices), maxSizeSlices(1, n - 1, slices));
    }
    int maxSizeSlices(int l, int r, vector<int>& slices) {
    	int n = r - l + 1;
    	// dp[i][j]: max nums of taking j slices among [0 + l, ..., 0 + l + i - 1]
    	vector<vector<int> > dp(n + 1, vector<int>(slices.size() / 3 + 1, 0));
    	dp[1][1] = slices[l];

    	for (int i = 2; i <= n; i++) {
    		for (int j = 1; j <= slices.size() / 3 && j <= (i + 1) / 2; j++) {
    			dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i + l - 1]);
    			// cout << "dp[" << i << "]" << "[" << j << "] = " << dp[i][j] << endl;
    		}
    	}
    	return dp[n][slices.size() / 3];
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int s[] = {3,1,2};
	vector<int> slices(s, s + sizeof(s) / sizeof(int));
	cout << sol.maxSizeSlices(slices) << endl;

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

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