#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int singleNonDuplicate(vector<int>& nums){
		int left = 0, right = nums.size()/2;
		while(right>left){
			int mid = (left+right)/2;

			if( (mid==0 && nums[mid*2]!=nums[mid*2+1]) || (mid==nums.size()/2 && nums[mid*2]!=nums[mid*2-1]) 
				|| (nums[mid*2]!=nums[mid*2-1] && nums[mid*2]!=nums[mid*2+1])){
				return nums[mid*2];
			}
			else{
				if(nums[mid*2]!=nums[mid*2+1]){
					right = mid;
				}
				else{
					left = mid+1;
				}
			}
		}
		return nums[left*2];
	}
};

int main(){
	int array[] = {3,3,7,7,10,11,11};
	vector<int> nums(array,array+7);

	Solution sol;
	cout<<sol.singleNonDuplicate(nums);
}