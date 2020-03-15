#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int cur = 1, max_freq = 0;
        for (int i = 1; i < nums.size(); ++i) {
        	if (nums[i] == nums[i - 1]) cur++;
        	else cur = 1;
        	max_freq = max(max_freq, cur);
        }
        return nums.size() >= K * max_freq;
    }
};

int main() {
	int n[] = {1,2,2,3,3,4,4};
	vector<int> nums(n, n + 7);
	int K = 3;
	Solution sol;
	cout << sol.canDivideIntoSubsequences(nums, K) << endl;
}