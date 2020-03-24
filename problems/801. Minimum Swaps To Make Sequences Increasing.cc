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
    int minSwap(vector<int>& A, vector<int>& B) {
    	int n = A.size();
    	// dp[i][0/1]: min swaps of 0...i and last one is 0:no swapped, 1:swapped
    	vector<vector<int> > dp(n, vector<int>(2, 9999));
    	dp[0][0] = 0;
    	dp[0][1] = 1;
    	for (int i = 1; i <= n; i++) {
    		// no swap
    		if (A[i] > A[i - 1] && B[i] > B[i - 1]) {	// [i - 1] no swap
    			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
    		}
    		if (A[i] > B[i - 1] && B[i] > A[i - 1]) {	// [i - 1] has swap
    			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    		}

    		// swap
    		if (B[i] > A[i - 1] && A[i] > B[i - 1]) {	// [i - 1] no swap
    			dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
    		}
    		if (B[i] > B[i - 1] && A[i] > A[i - 1]) {	// [i - 1] has swap
    			dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
    		}
    	}
    	return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,3,5,4}, b[] = {1,2,3,7};
	vector<int> A(a, a + sizeof(a) / sizeof(int)), B(b, b + sizeof(b) / sizeof(int));
	cout << sol.minSwap(A, B) << endl;

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