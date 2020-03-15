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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int total = min(5000, accumulate(rods.begin(), rods.end(), 0) / 2);

        vector<vector<int> > dp(n + 1, vector<int>(total + 1, INT_MIN));
        dp[0][0] = 0;
        for (int i = 1; i < n + 1; ++i) {
        	for (int j = 0; j < total + 1; ++j) {
        		dp[i][j] = dp[i - 1][j];
        		if (rods[i - 1] > total) continue;
        		if (rods[i - 1] <= j) {
        			dp[i][j] = max(dp[i][j], dp[i - 1][j - rods[i - 1]] + rods[i - 1]);
        		}
        		if (rods[i - 1] > j) {
        			dp[i][j] = max(dp[i][j], dp[i - 1][rods[i - 1] - j] + j);
        		}
        		if (rods[i - 1] + j < total + 1) {
        			dp[i][j] = max(dp[i][j], dp[i - 1][rods[i - 1] + j]);
        		}
        	}
        }
        return dp[n][0];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int r[] = {1,2};
	vector<int> rods(r, r + 2);
	cout << sol.tallestBillboard(rods) << endl;

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