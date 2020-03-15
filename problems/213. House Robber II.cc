#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//     	if (nums.size() == 0) return 0;
//     	if (nums.size() == 1) return nums[0];
//     	return max(straightRob(nums, 0, nums.size()-2), straightRob(nums, 1, nums.size()-1));
//     }

//     int straightRob(vector<int> &nums, int start, int end) {
//     	if (start > end) return 0;
//     	if (end - start == 0) return nums[start];

//     	int cur = max(nums[start], nums[start + 1]);
//     	int pre = nums[start];
//     	for (int i = start + 2; i <= end; ++i) {
//     		int temp = cur;
//     		cur = max(cur, pre + nums[i]);
//     		pre = temp;
//     	}
//     	return cur;
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        // robbed house 0
        int ans1 = nums[0] + straight_rob(2, n - 2, nums);
        // not rob house 0
        int ans2 = straight_rob(1, n - 1, nums);
        return max(ans1, ans2);
    }
    int straight_rob(int s, int e, vector<int>& nums) {
        int n = e - s + 1;
        if (n <= 0) return 0;
        if (n <= 2) return *max_element(nums.begin() + s, nums.begin() + e + 1);
        
        // dp[i] = maximum profit from first i houses
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        vector<int> dp(n, 0);
        dp[0] = nums[s];
        dp[1] = *max_element(nums.begin() + s, nums.begin() + s + 2);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], nums[i + s] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};

int main() {
	int array[] = {4,1,2,7,5,3,1};
	vector<int> nums(array, array + 7);

	Solution sol;
	cout << sol.rob(nums);
}