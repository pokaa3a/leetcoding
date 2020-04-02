#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
	int checkRecord(int n) {
		const long M = 1e9 + 7;
		vector<vector<long long>> dp(n + 1, vector<long long>(6, 0));
		// six states:
		// 0: has a A / last one is L
		// 1: has a A / last two are Ls
		// 2: has a A / last two are not both Ls (LX or XX)
		// 3: has No A / last one is L
		// 4: has No A / last two are Ls
		// 5: has No A / last two are not both Ls (LX or XX)

		// Initialize
		dp[0][5] = 1;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][2] % M;
			dp[i][1] = dp[i - 1][0] % M;
			dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % M + (dp[i - 1][2] + dp[i - 1][3]) % M + (dp[i - 1][4] + dp[i - 1][5]) % M;
			dp[i][3] = dp[i - 1][5] % M;
			dp[i][4] = dp[i - 1][3] % M;
			dp[i][5] = ((dp[i - 1][3] + dp[i - 1][4]) % M + dp[i - 1][5]) % M;
		}

		return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5]) % M;
	}
};

int main() {
	Solution sol;
	int n = 100;
	cout << sol.checkRecord(n) << endl;
}