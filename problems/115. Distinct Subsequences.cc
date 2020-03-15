class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(t.length(),0);
        for(int i=0; i<s.length(); i++){
            for(int j=t.length()-1; j>=0; j--){
                if(s[i]==t[j]) dp[j] = (j==0 ? 1 : dp[j-1]) + dp[j];
            }
        }
        return dp[t.length()-1];
    }
};