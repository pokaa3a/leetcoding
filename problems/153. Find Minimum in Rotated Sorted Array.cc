#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums){
		int left = 0, right = nums.size()-1;

		while(right>left){
			int mid = (left+right)/2;
			if( (mid==0 && nums[mid]<=nums[nums.size()-1]) || nums[mid]<=nums[mid-1] ){
				return nums[mid];
			}
			else{
				if(nums[mid]>nums[right]){
					left = mid+1;
				}
				else{
					right = mid;
				}
			}
		}
		return nums[left];
	}
};

int main(){
	int array[] = {0};
	vector<int> nums(array,array+1);
	Solution sol;
	cout<<sol.findMin(nums);
}