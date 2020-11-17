class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] >= '1') dp[i + 1] += dp[i];
            if (i >= 1) {
                int two = stoi(s.substr(i - 1, 2));
                if (two >= 10 && two <= 26) {
                    dp[i + 1] += dp[i - 1];
                }
            }
        }
        return dp[n];
    }
};