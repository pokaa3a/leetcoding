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
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> dp(A.size() + 1, 0);
       	map<int, int> sums;
       	sums[0] = 1;

        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
        	dp[i + 1] = dp[i] + A[i];
        	ans += sums[dp[i + 1] - S];

        	sums[dp[i + 1]]++;
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
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);
	int a[] = {1,0,1,0,1}, S = 2;
	vector<int> A(a, a + 5);
	cout << sol.numSubarraysWithSum(A, S) << endl;

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