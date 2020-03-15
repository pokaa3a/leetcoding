#include <iostream>
#include <vector>
using namespace std;

// DP
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		// define state:
		// dp[i]: length of longest increasing subsequence that ends with nums[i]
		vector<int> dp(nums.size(), 1);

		// transition function: dp[i] = dp[j] + 1 for j s.t. j < i && nums[j] < nums[i] && dp[j] >= dp[i]
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
			}
		}
		return nums.size() == 0 ? 0 : *max_element(dp.begin(), dp.end());
	}
};

// overlapping
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		// lis[i]: minimum last number of subsequence with its length as i
		vector<int> lis;
		for (int i = 0; i < nums.size(); ++i) {
			int x = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
			if (x >= lis.size()) lis.push_back(nums[i]);
			else lis[x] = nums[i];
		}
		return lis.size();
	}
};

// class Solution {
// public:
// 	int lengthOfLIS(vector<int> &nums) {
// 		vector<int> tails(nums.size(), 0);
// 		int length = 0;

// 		for (int i = 0; i < nums.size(); ++i) {
// 			// look for the minimum k s.t. tails[k] >= nums[i]
// 			int low = lower_bound(tails.begin(), tails.begin() + length, nums[i]) - tails.begin();
// 			tails[low] = nums[i];
// 			length = max(low + 1, length);
// 		}
// 		return length;
// 	}
// };

int main() {
	int array[] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> nums(array, array + 8);

	Solution sol;
	cout << sol.lengthOfLIS(nums);
}