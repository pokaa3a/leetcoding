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
    int maxSumBST(TreeNode* root) {
        ans = 0;
        int d1, d2, d3;
        dfs(root, d1, d2, d3);
        return ans;
    }
    bool dfs(TreeNode* root, int& mini, int& maxi, int& sum) {
    	if (!root) {
    		mini = INT_MAX;
    		maxi = INT_MIN;
    		sum = 0;
    		return true;
    	}
    	int left_min, left_max, left_sum, right_min, right_max, right_sum;
    	int left = dfs(root->left, left_min, left_max, left_sum);
    	int right = dfs(root->right, right_min, right_max, right_sum);

    	if (left && right &&
    		left_max < root->val && right_min > root->val) {
    		mini = min(root->val, left_min);
    		maxi = max(root->val, right_max);
    		sum = root->val + left_sum + right_sum;
    		ans = max(ans, sum);
    		return true;
    	}
    	return false;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

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