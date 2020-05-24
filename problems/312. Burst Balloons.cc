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
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> new_nums(n, 1);
        for (int i = 0; i < nums.size(); i++) {
        	new_nums[i + 1] = nums[i];
        }
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return dp(new_nums, memo, 0, n - 1);
    }
    int dp(vector<int>& nums, vector<vector<int>>& memo, int left, int right) {
    	if (left + 1 == right) return 0;
    	if (memo[left][right] != 0) return memo[left][right];

    	for (int i = left + 1; i < right; i++) {
    		memo[left][right] = max(memo[left][right], nums[left] * nums[i] * nums[right] + 
    												   dp(nums, memo, left, i) + dp(nums, memo, i, right));
    	}
    	return memo[left][right];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> nums = {3,1,5,8};
	cout << sol.maxCoins(nums) << endl;

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