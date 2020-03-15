#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k >= prices.size() / 2) return quickSolve(prices);
		vector<vector<int> > dp(k + 1, vector<int>(prices.size(), 0));
		for (int i = 1; i <= k; ++i) {
			int tmpMax = - prices[0];
			for (int j = 1; j < prices.size(); ++j) {
				dp[i][j] = max(dp[i][j-1], prices[j] + tmpMax);
				tmpMax = max(tmpMax, dp[i-1][j-1] - prices[j]);
			}
		}
		return dp[k][prices.size()-1];
	}

	int quickSolve(vector<int>& prices) {
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			profit = prices[i] - prices[i-1] > 0 ? profit + prices[i] - prices[i-1] : profit;
		}
		return profit;
	}
};

int main() {
	int array[] = {3,2,6,5,0,3};
	vector<int> prices(array, array+6);
	int k = 2;

	Solution sol;
	cout << sol.maxProfit(k, prices);
}