#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int mini = INT_MAX;
		int second_seq = INT_MAX;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > second_seq) return true;
			mini = min(mini, nums[i]);
			if (nums[i] > mini && nums[i] < second_seq) second_seq = nums[i];
		}
		return false;
	}
};

int main() {
	// int array1[] = {1, 2, 3, 4, 5};
	// vector<int> nums1(array1, array1 + 5);
	int array2[] = {1, 2, 3};
	vector<int> nums2(array2, array2 + 3);

	Solution sol;
	cout << sol.increasingTriplet(nums2) << endl;
}