#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMajorityElement(vector<int>& nums, int target) {
		int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		// cout << "left: " << left << endl;
		int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
		// cout << "right: " << right << endl;
		return (right - left) > nums.size() / 2 ? true : false;
	}
};

int main() {
	int a[] = {10, 100, 101, 101};
	vector<int> nums(a, a + 4);

	int target = 101;

	Solution sol;
	cout << sol.isMajorityElement(nums, target) << endl;
}