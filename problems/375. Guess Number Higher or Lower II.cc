#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int getMoneyAmount(int n) {
		// dp[i][j]: min cost of range i to j
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
		// dp[i][j] = min_{k from i to j} (k + max(dp[i][k - 1], dp[k + 1][j]))

		for (int i = 1; i <= n; i ++) {
			dp[i][i] = 0;	// len == 1 : no need to guess
		}
		int ans = 0;
		for (int len = 2; len <= n; len++) {
			for (int i = 1; i <= n - 1; i++) {
				int j = i + len - 1;
				if (j > n) break;
				// cout << "i: " << i << " j: " << j << endl;
				for (int k = i; k <= min(j, n); k++) {
					// cout << "k: " << k << endl;
					if (k == i) {
						dp[i][j] = min(dp[i][j], k + dp[k + 1][j]);
					} else if (k == j) {
						dp[i][j] = min(dp[i][j], k + dp[i][k - 1]);
					} else {
						dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
					}
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};

int main() {
	int n = 3;
	Solution sol;
	cout << sol.getMoneyAmount(n) << endl;
}