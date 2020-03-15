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
    int subarraysDivByK(vector<int>& A, int K) {
        int ans = 0;
        vector<int> dp(A.size() + 1, 0);
        vector<int> mods(K, 0);

        for (int i = 0; i < A.size(); ++i) {
        	dp[i + 1] = ((dp[i] + A[i]) % K + K) % K;
        	ans += mods[dp[i + 1]];

        	mods[dp[i + 1]]++;
        	if (dp[i + 1] == 0) ans++;
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {4,5,0,-2,-3,1}, K = 5;
	vector<int> A(a, a + 6);
	cout << sol.subarraysDivByK(A, K) << endl;

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