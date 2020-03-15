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
    int distinctSubseqII(string S) {
        map<char, int> ends;
        vector<int> dp(S.size() + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= S.size(); ++i) {
        	int pre = dp[i - 1];
        	dp[i] = ((2 * dp[i - 1]) % MOD - ends[S[i - 1]] + MOD) % MOD;
        	ends[S[i - 1]] = pre;
        	// cout << "dp[" << i << "] = " << dp[i] << endl;
        	// cout << "ends[" << S[i - 1] << "] = " << ends[S[i - 1]] << endl;
        }
        return (dp[S.size()] - 1) % MOD;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string S = "abc";
	cout << sol.distinctSubseqII(S) << endl;

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