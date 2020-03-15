class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<26> b;
        for(int i=0; i<s.length(); i++){
            b[s[i]-'a'].flip();
        }
        return b.count()<2;
    }
};