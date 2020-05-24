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
    int constrainedSubsetSum(vector<int>& nums, int k) {  
        int n = nums.size();
        vector<int> dp(n, 0); // dp[i]: max sum end with i
        deque<int> q;
        
        int res = nums[0];
        dp[0] = nums[0];
        q.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], nums[i] + dp[q.front()]);
            res = max(res, dp[i]);
            
            while (!q.empty() && dp[q.back()] < dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
            
            // handle sliding window
            if (q.front() == i - k) {
                q.pop_front();
            }
        }
        return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> nums = {10, 2, -10, 5, 20};
	int k = 2;
	cout << sol.constrainedSubsetSum(nums, k);

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