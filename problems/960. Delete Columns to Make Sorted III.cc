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
    int minDeletionSize(vector<string>& A) {
        int n = A[0].size();

        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
        	for (int j = 0; j < i; ++j) {
        		bool a = true;
        		for (int k = 0; k < A.size(); ++k) {
        			if (A[k][j] > A[k][i]) {
        				a = false;
        				break;
        			}
        		}
        		if (a && dp[j] + 1 > dp[i]) {
        			dp[i] = dp[j] + 1;
        		}
        	}
        }
        for (int i = 0; i < dp.size(); ++i) cout << dp[i] << " ";
        cout << endl;

        return n - *max_element(dp.begin(), dp.end());
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> A;
	A.push_back("baabab");
	// A.push_back("def");
	// A.push_back("abc");

	cout << sol.minDeletionSize(A) << endl;

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