#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4 (vector<int> &nums, int target) {
		vector<unsigned int> dp(target + 1, 0);
		sort(nums.begin(), nums.end());

		dp[0] = 1;
		for (int t = 1; t <= target; ++t) {
			for (int i = 0; i < nums.size() && nums[i] <= t; ++i) {
				dp[t] += dp[t - nums[i]];
			}
		}
		return target == 0 ? 0 : dp[target];
	}
};

int main () {
	int array[] = {1, 2, 3};
	vector<int> nums(array, array + 3);
	Solution sol;
	cout << sol.combinationSum4 (nums, 3) << endl;
}