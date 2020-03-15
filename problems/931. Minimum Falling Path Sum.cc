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
    int minFallingPathSum(vector<vector<int> >& A) {
    	int n = A.size();

    	// dp[i][j]: min sum from 0 to i-th row and ends at j
    	vector<vector<int> > dp(n, vector<int>(n, 0));

    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			if (i == 0) dp[i][j] = A[0][j];
    			else {
    				if (j == 0) {
    					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + A[i][j];
    				} else if (j == n - 1) {
    					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + A[i][j];
    				} else {
    					dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + A[i][j];
    				}
    			}
    		}
    	}
    	return *min_element(dp.back().begin(), dp.back().end());
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 3;
	const int cols = 3;
	int arr[rows][cols] = {{1,2,3}, {4,5,6}, {7,8,9}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.minFallingPathSum(grid) << endl;

	/* [String] */
	// string str = "";

}