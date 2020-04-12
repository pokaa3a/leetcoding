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
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(27, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                for (int k = 0; k < 3; k++) {
                    if (k == j) continue;
                    int code = 9 * i + 3 * j + k;
                    dp[1][code] = 1;
                }
            }
        }
        for (int r = 2; r <= n; r++) {
             for (int code0 = 0; code0 < 27; code0++) {
                 int i0 = code0 / 9;
                 int j0 = code0 % 9 / 3;
                 int k0 = code0 % 9 % 3;
                 for (int i = 0; i < 3; i++) {
                     if (i == i0) continue;
                     for (int j = 0; j < 3; j++) {
                         if (j == i || j == j0) continue;
                         for (int k = 0; k < 3; k++) {
                             if (k == j || k == k0) continue;
                             int code = 9 * i + 3 * j + k;
                             dp[r][code] = (dp[r][code] + dp[r - 1][code0]) % MOD;
                         }
                     }
                 }
             }
        }
        long long output = 0;
        for (int i = 0; i < 27; i++) output = (output + dp[n][i]) % MOD;
        return (int)output;
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