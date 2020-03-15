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
    bool isValidPalindrome(string s, int k) {
        string r_s = s;
        reverse(r_s.begin(), r_s.end());

        int n = s.size();
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
        	for (int j = 1; j <= n; ++j) {
        		if (s[i - 1] == r_s[j - 1]) {
        			dp[i][j] = dp[i - 1][j - 1] + 1;
        		} else {
        			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        		}
        	}
        }
        return n - dp[n][n] <= k;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "abcdeca";
	int k = 2;
	cout << sol.isValidPalindrome(s, k) << endl;

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