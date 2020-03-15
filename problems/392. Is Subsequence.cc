class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="") return true;
        int start=0;
        for(int i=0; i<s.length(); i++){
            for(; start<t.length(); start++){
                if(s[i]==t[start]){
                    if(i==s.length()-1) return true;
                    start++;
                    break;
                }
            }
        }
        return false;
    }
};