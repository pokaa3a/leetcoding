class Solution {
public:
    void helper(string s, vector<string> &res, int m, int n){
        if(m==0&&n==0){
            res.push_back(s);
            return;
        }
        if(n>0) helper(s+")",res,m,n-1);
        if(m>0) helper(s+"(",res,m-1,n+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("",res,n,0);
        return res;
    }
};