class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int res = 0;
        vector<int> dp(s.length(),1);
        for(int i=1; i<s.length(); i++){
            int len = 0;
            for(int j=i-1; j>=0; j--){
                int reg = dp[j];
                if(s[i]==s[j]){
                    dp[j] = len+2;
                }
                len = reg>len?reg:len;
            }
        }
        
        for(int i=0; i<s.length(); i++){
            res = max(res, dp[i]);
        }
        return res;
    }
};