#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> presum(n + 1, 0);
		unordered_map<int, int> sum2idx;
		sum2idx[0] = 0;

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			presum[i] = nums[i - 1] + presum[i - 1];
			
			int target = presum[i] - k;
			if (sum2idx.find(target) != sum2idx.end()) {
				ans = max(ans, i - sum2idx[target]);
			}
			if (sum2idx.find(presum[i]) == sum2idx.end()) {
				sum2idx[presum[i]] = i;
			}
		}
		return ans;
	}
};

int main() {
	// vector<int> nums = {1, -1, 5, -2, 3};
	vector<int> nums = {-2, -1, 2, 1};
	int k = 1;
	Solution sol;
	cout << sol.maxSubArrayLen(nums, k) << endl;
}