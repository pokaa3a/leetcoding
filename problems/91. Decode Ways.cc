class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0 || s[0]=='0') return 0;
        
        int pre=1, next=1,res=1;
        for(int i=1; i<n; i++){
            if(s[i]=='0') next=0;
            if(!(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6')) pre=0;
            res = pre+next;
            pre = next;
            next = res;
        }
        return res;
    }
};