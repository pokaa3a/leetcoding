#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int> &nums) {
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++i) {
			int index = abs(nums[i]) - 1;
			if (nums[index] < 0) {
				ans.push_back(index + 1);
			}
			nums[index] *= -1;
		}
		return ans;
	}
};

int main() {
	int array[] = {4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> nums(array, array + 8);

	Solution sol;
	vector<int> ans = sol.findDuplicates(nums);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
}