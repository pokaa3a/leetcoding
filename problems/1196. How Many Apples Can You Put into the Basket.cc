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
// class Solution {
// public:
//     int maxNumberOfApples(vector<int>& arr) {
//         int n = arr.size();
//         int W = 5000;
//         vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));
//         for (int i = 0; i <= n; ++i) {
//         	for (int w = 0; w <= W; ++w) {
//         		if (i == 0 || w == 0) {
//         			dp[i][w] = 0;
//         		} else if (arr[i - 1] <= w) {
//         			dp[i][w] = max(dp[i - 1][w - arr[i - 1]] + 1, dp[i - 1][w]);
//         		} else {
//         			dp[i][w] = dp[i - 1][w];
//         		}
//         	}
//         }
//         return dp[n][W];
//     }
// };

// class Solution {
// public:
//     int maxNumberOfApples(vector<int>& arr) {
//         return knapSack(5000, arr.size(), arr);
//     }
//     int knapSack(int w, int n, vector<int>& arr) {
//     	if (n == 0) return 0;
//     	if (arr[n - 1] > w) {
//     		return knapSack(w, n - 1, arr);
//     	} else {
//     		return max(knapSack(w - arr[n - 1], n - 1, arr) + 1, 
//     				   knapSack(w, n - 1, arr));
//     	}
//     }
// };

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int remain = 5000;
        int ans = 0;
        for (int i = 0; i < arr.size() && remain > 0; ++i) {
            remain -= arr[i];
            if (remain > 0) ans++;
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	int arr[] = {900,950,800,1000,700,800};
	vector<int> nums(arr, arr + 6);
	cout << sol.maxNumberOfApples(nums) << endl;

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