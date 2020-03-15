#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int twoSumSmaller(vector<int> nums, int start, int target){
		int sum = 0;
		int left = start, right = nums.size()-1;

		while(left<right){
			if(nums[left]+nums[right]<target){
				sum += right-left;
				left++;
			}
			else{
				right--;
			}
		}
		return sum;
	}

    int threeSumSmaller(vector<int>& nums, int target) {
    	if(nums.size()<3) return 0;
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<nums.size()-2; i++){
        	sum += twoSumSmaller(nums, i+1, target-nums[i]);
        }
        return sum;
    }
};

int main(){
	int array[] = {-2, 0, 1, 3};
	vector<int> nums(array, array+4);

	Solution sol;
	cout<<sol.twoSumSmaller(nums, 0, 2);
}