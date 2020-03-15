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
    int mergeStones(vector<int>& stones, int K) {
    	if (stones.size() == 1) return 0;
    	int n = stones.size();
    	if ((n - 1) % (K - 1)) return -1;

    	vector<int> sums(n, 0);
    	for (int i = 0; i < n; ++i) {
    		sums[i] = (i == 0 ? 0 : sums[i - 1]) + stones[i];
    	}

    	vector<vector<int> > dp(n, vector<int>(n, 0));
    	for (int m = K; m <= n; ++m) {
    		for (int i = 0; i + m - 1 < n; ++i) {
    			int j = i + m - 1;
    			dp[i][j] = INT_MAX;
    			cout << "K: " << K << endl;
    			cout << "i: " << i << ", j: " << j << endl;
    			for (int mid = i; mid < j; mid += K - 1) {
    				cout << "mid: " << mid << endl;
    				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
    			}
    			if ((j - i) % (K - 1) == 0) {
    				dp[i][j] += sums[j] - (i == 0 ? 0 : sums[i - 1]);
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
	int s[] = {3,5,1,2,6};
	vector<int> stones(s, s + 5);
	int K = 3;
	cout << sol.mergeStones(stones, K) << endl;
}