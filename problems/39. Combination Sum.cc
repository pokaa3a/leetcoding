class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> nums;
        helper(candidates, target, res, nums, 0);
        return res;
    }
    
    void helper(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> nums, int begin){
        if(target==0) {
            res.push_back(nums);
            return;
        }
        
        for(int i=begin; i<candidates.size() && candidates[i]<=target; i++){
            nums.push_back(candidates[i]);
            helper(candidates, target-candidates[i], res, nums, i);
            nums.pop_back();
        }
    }
};