class Solution {
private:
    map<int, string> hash;
public:
    vector<string> letterCombinations(string digits) {
        hash[0] = "";
        hash[1] = "";
        hash[2] = "abc";
        hash[3] = "def";
        hash[4] = "ghi";
        hash[5] = "jkl";
        hash[6] = "mno";
        hash[7] = "pqrs";
        hash[8] = "tuv";
        hash[9] = "wxyz";
        
        vector<string> res;
        if(digits.length()==0) return res;
        string combo;
        helper(digits, combo, res);
        return res;
    }
    void helper(string digits, string combo, vector<string> &res){
        if(digits.length()==0){
            res.push_back(combo);
            return;
        }
        
        int num = digits[0]-'0';
        string letters = hash[num];
        for(int i=0; i<letters.length(); i++){
            combo = combo+letters[i];
            helper(digits.substr(1), combo, res);
            combo = combo.substr(0, combo.length()-1);
        }
        
    }
};