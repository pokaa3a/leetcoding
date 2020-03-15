#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 1, right;
		for (int i=1; i<nums.size(); ++i) {
			right = nums[i] - nums[i-1];
			if (left * right < 0) return i-1;
			left = right;
		}
		return nums.size()-1;
	}
};

int main(){
	int array[] = {1,2,1,3,5,6,4};
	vector<int> nums(array, array+7);

	Solution sol;
	cout << sol.findPeakElement(nums);
}