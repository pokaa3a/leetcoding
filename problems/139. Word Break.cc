class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> hash;
        for(int i=0; i<wordDict.size(); i++){
            hash[wordDict[i]] = true;
        }
        
        vector<bool> dp(s.length()+1);
        dp[0] = true;
        
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=i; j++){
                string str = s.substr(i-j,j);
                if(hash.find(str)!=hash.end()){
                    dp[i] = dp[i-j];
                    if(dp[i]) break;
                }
            }
        }
        return dp[s.length()];
    }
};