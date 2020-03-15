#include <iostream>
#include <vector>
using namespace std;

// solution - 1: DP
// class Solution {
// public:
// 	bool canPartition(vector<int> &nums) {
// 		int sum = 0;
// 		for (int i = 0; i < nums.size(); ++i) {
// 			sum += nums[i];
// 		}
// 		if (sum & 1) return false;
// 		int target = sum >> 1;

// 		vector<bool> dp(target + 1, false);
// 		dp[0] = true;
// 		for (int i = 0; i < nums.size(); ++i) {
// 			for (int t = target; t >= nums[i]; --t) {
// 				dp[t] = dp[t] | dp[t - nums[i]];
// 			}
// 			if (dp[target]) return true;
// 		}
// 		return false;
// 	}
// };

// solution - 2: DFS
bool cmp (int a, int b) {return a > b;}

class Solution {
public:
	bool canPartition(vector<int> &nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
		}
		if (sum & 1) return false;
		int target = sum >> 1;
		sort(nums.begin(), nums.end(), cmp);
		return canReach(nums, target, 0, sum);
	}
private:
	bool canReach(vector<int> &nums, int target, int start, int remain) {
		for (int i = start; i < nums.size(); ++i) {
			remain -= nums[i];
			if (nums[i] > target) continue;
			if (nums[i] == target || remain == target) return true;
			if (canReach(nums, target - nums[i], i + 1, remain)) return true;
			if (remain < target) return false;
		}
		return false;
	}
};

int main() {
	int array[] = {1, 5, 11, 5};
	vector<int> nums(array, array + 4);

	Solution sol;
	cout << sol.canPartition(nums) << endl;
}