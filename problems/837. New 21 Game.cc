#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double new21Game(int N, int K, int W) {
		if (K == 0) return 1.0;

		vector<double> dp(K + W + 1, 0.0);
		for (int i = K; i <= N; ++i) {
			dp[i] = 1.0;
		}
		dp[K - 1] = (N - K + 1) / (double)W;

		for (int i = K - 2; i >= 0; --i) {
			dp[i] = dp[i + 1] + (dp[i + 1] - dp[i + W + 1]) / W;
		}
		return dp[0];
	}
};

int main() {
	int N = 0, K = 0, W = 10;
	Solution sol;
	cout << sol.new21Game(N, K, W) << endl;
}