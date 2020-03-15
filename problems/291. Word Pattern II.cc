class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        return helper(pattern, 0, str, 0);
    }
    bool helper(string &pattern, int p, string &str, int s){
        if(p==pattern.length() && s==str.length()) return true;
        if(pattern.length()-p > str.length()-s || p==pattern.length()) return false;
        if(p2s.find(pattern[p])==p2s.end()){
            for(int i=1; s+i<=str.length(); i++){
                string reg = str.substr(s,i);
                if(s2p.find(reg)!=s2p.end()) continue;
                p2s[pattern[p]] = reg;
                s2p[reg] = pattern[p];
                if(helper(pattern, p+1, str, s+i)) return true;
                p2s.erase(pattern[p]);
                s2p.erase(reg);
            }
            return false;
        } else {
            string reg = p2s[pattern[p]];
            if(reg == str.substr(s,reg.length())){
                return helper(pattern, p+1, str, s+reg.length());
            } else return false;
        }
    }
private:
    map<char, string> p2s;
    map<string, char> s2p;
};