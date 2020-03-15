#include <iostream>
#include <vector>
using namespace std;

/*
For such positive / negative problems, can memorize both
positive and negative products.
*/

class Solution{
public:
	int maxProduct(vector<int>& nums){
		int r = nums[0];
		for (int i = 1, imax = r, imin = r; i < nums.size(); i++) {
			if (nums[i] < 0) {
				swap(imax, imin);
			}
			imax = max(nums[i], imax * nums[i]);
			imin = min(nums[i], imin * nums[i]);
			r = max(r, imax);
		}
		return r;
	}
};

int main(){
	int array[] = {2, 3, -2, 4};
	vector<int> nums(array, array+4);

	Solution sol;
	cout << sol.maxProduct(nums);
}