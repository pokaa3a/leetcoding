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
    double probabilityOfHeads(vector<double>& prob, int target) {
		int n = prob.size();
		vector<vector<double> > dp(n + 1, vector<double>(target + 1, 0));
		dp[0][0] = 1;

		for (int t = 0; t <= target; ++t) {
			for (int i = 1; i <= n; ++i) {
				if (i < t) {
					dp[i][t] = 0;
				} else {
					dp[i][t] = (t == 0 ? 0 : dp[i - 1][t - 1] * prob[i - 1]) + 
							   dp[i - 1][t] * (1 - prob[i - 1]);
				}
			}
		}
		return dp[n][target];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	const int a = 5;
	double arr[] = {0.5,0.5,0.5,0.5,0.5};
	vector<double> nums(arr, arr + a);
	int target = 0;
	cout << sol.probabilityOfHeads(nums, target) << endl;

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