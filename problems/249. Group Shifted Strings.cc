class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        for(int i=0; i<strings.size(); i++){
            string reg;
            for(int j=0; j<strings[i].size(); j++){
                char c = strings[i][j]-strings[i][0];
                if(c<0) c+=26;
                reg += c;
            }
            if(hash.find(reg)!=hash.end()){
                result[hash[reg]].push_back(strings[i]);
            } else {
                hash[reg] = result.size();
                result.push_back(vector<string>(1,strings[i]));
            }
        }
        return result;
    }
private:
    map<string, int> hash;
};