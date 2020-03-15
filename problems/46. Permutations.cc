class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        
        helper(nums, res, 0);
        return res;
    }
    
    void helper(vector<int> nums, vector<vector<int>> &res, int start){
        
        for(int i=start; i<nums.size(); i++){
            swap(nums[start], nums[i]);
            if(start==nums.size()-1){
                res.push_back(nums);
            }
            helper(nums, res, start+1);
            swap(nums[i],nums[start]);
        }
        
    }
};