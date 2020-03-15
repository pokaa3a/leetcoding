class Solution {
public:
    void dp(string s, int n, vector<string> &res, string ip){
        if(n==4){
            if(s.length()==0){
                res.push_back(ip);
            }
        }else{
            for(int k=1; k<=3; k++){
                if(s.length()<k) break;
                int val = stoi(s.substr(0,k));
                if(val>255 || to_string(val).length()!=k) continue;
                dp(s.substr(k), n+1, res, ip+s.substr(0,k)+(n==3?"":"."));
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dp(s, 0, res, "");
        return res;
    }
};