#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int> &nums) {
		int missing = 0;
		if (nums.size() % 2 == 0) nums.push_back(nums.size() + 1);
		vector<int> tags((nums.size() + 1) / 2, -1);
		for (int i = 0; i < nums.size(); ++i) {
			missing ^= nums[i] % 2 ? nums[i] : nums[i] + 1;
			tags[nums[i] / 2] = nums[i] % 2 ? 1 : 0;
		}
		return tags[missing / 2] ? missing - 1 : missing;
	}
};

int main() {
	int array[] = {1, 2};
	vector<int> nums(array, array + 2);
	Solution sol;
	cout << sol.missingNumber(nums);
}