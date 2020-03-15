#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); ++i) {
			int coin = coins[i];
			for (int j = coin; j <= amount; ++j) {
				dp[j] += dp[j - coin];
			}
		}
		return dp[amount];
	}
};

int main() {
	int coins_array[] = {1, 2, 5};
	vector<int> coins(coins_array, coins_array + 3);
	int amount = 5;
	Solution sol;
	cout << sol.change(amount, coins) << endl;
}