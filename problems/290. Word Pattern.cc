class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream istr(str);
        string s;
        vector<string> vs;
        while(istr>>s) vs.push_back(s);
        
        if(pattern.length()!=vs.size()) return false;
        
        for(int i=0; i<vs.size(); i++){
            if(p2s[pattern[i]]=="" && s2p[vs[i]]==0){
                p2s[pattern[i]] = vs[i];
                s2p[vs[i]] = pattern[i];
                continue;
            }
            if(p2s[pattern[i]]!=vs[i]) return false;
        }
        return true;
    }
private:
    map<char, string> p2s;
    map<string, char> s2p;
};