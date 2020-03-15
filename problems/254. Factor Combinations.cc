class Solution {
public:
    void helper(vector<vector<int>> &result, vector<int> &row, int n){
        int i = row.empty()? 2:row.back();
        for(; i<=n/i; i++){
            if(n%i==0){
                row.push_back(i);
                row.push_back(n/i);
                result.push_back(row);
                row.pop_back();
                helper(result, row, n/i);
                row.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> row;
        helper(result, row, n);
        return result;
    }
};