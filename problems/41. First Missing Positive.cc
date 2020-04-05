#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		bool hasOne = false;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 1) hasOne = true;
			else if (nums[i] < 1 || nums[i] > n) nums[i] = 1;
		}
		if (!hasOne) return 1;
		if (n == 1) return 2;
		for (auto x : nums) {
			nums[abs(x) - 1] = -abs(nums[abs(x) - 1]);
		}
		int first_pos = 1;
		while (first_pos <= n) {
			if (nums[first_pos - 1] > 0) return first_pos;
			first_pos++;
		}
		return first_pos;
	}
};

int main() {
	vector<int> nums = {1,2,8,9,11,12,4,5};
	Solution sol;
	cout << sol.firstMissingPositive(nums) << endl;
}