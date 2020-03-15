class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i=1; i<=amount; i++){
            for(int k=0; k<coins.size(); k++){
                if(coins[k]>i) break;
                if(dp[i-coins[k]]>=0){
                    dp[i] = dp[i]>0?min(dp[i],dp[i-coins[k]]+1):dp[i-coins[k]]+1;
                }
            }
        }
        return dp[amount];
    }
};