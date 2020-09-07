class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        // dp[i] == minimum coins need for amount i
        dp[0] = 0; 
        
        for (int i = 0; i <= amount; i++) {
            for (int c : coins) {
                if (c <= i && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};