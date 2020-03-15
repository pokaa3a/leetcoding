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

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
    	int n = A.size();
    	vector<vector<int> > dp(n, vector<int>(n, 0));

    	for (int j = 2; j < n; ++j) {
    		for (int i = j - 2; i >= 0; --i) {
    			dp[i][j] = INT_MAX;
    			for (int k = i + 1; k < j; ++k) {
    				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
    			}
    		}
    	}
    	return dp[0][n - 1];
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {1,3,1,4,1,5};
	vector<int> A(a, a + 6);
	cout << sol.minScoreTriangulation(A) << endl;
}