class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(target == nums[mid]) return mid;
            if((nums[mid]>=nums[left] && (target>nums[mid] || (target<nums[left]))) || (nums[mid]<nums[left] && target>nums[mid] && target<=nums[right]))
                left = mid + 1;
            else
                right = mid -1;
        }
        return -1;
    }
};