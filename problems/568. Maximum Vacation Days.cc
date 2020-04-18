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
// O(N^2 * K)
// N cities, K weeks
// filling a table of size (N, K)
// filling each cell needs O(N)
class Solution {
public:
    int N, K;
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        N = flights.size(); // # of cities
        K = days[0].size(); // # of weeks
        vector<vector<int>> dp(N, vector<int>(K, -1));
        int max_holidays = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0 || flights[0][i] == 1) {
                max_holidays = max(max_holidays, helper(i, 0, dp, flights, days));
            }
        }
        return max_holidays;
    }
    int helper(int n, int k, vector<vector<int>>& dp,
               vector<vector<int>>& flights, vector<vector<int>>& days) {
        if (dp[n][k] != -1) return dp[n][k];
        
        if (k == K - 1) {   // last week
            dp[n][k] = days[n][k];
            return dp[n][k];
        }
        
        int next_holidays = 0;
        for (int i = 0; i < N; i++) {
            if (i == n || flights[n][i] == 1) {
                next_holidays = max(next_holidays, helper(i, k + 1, dp, flights, days));
            }
        }
        dp[n][k] = days[n][k] + next_holidays;
        return dp[n][k];
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