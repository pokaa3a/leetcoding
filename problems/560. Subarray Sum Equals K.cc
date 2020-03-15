#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int> &nums, int k) {
		unordered_map<int, int> sum_map;
		int sum = 0;
		int ans = 0;
		sum_map[0] = 1;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			ans += sum_map[sum - k];
			sum_map[sum]++;
		}
		return ans;
	}
};

int main() {
	int array[] = {1, 1, 1};
	vector<int> nums(array, array + 3);
	Solution sol;
	cout << sol.subarraySum(nums, 2) << endl;
}