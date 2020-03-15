#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int> &nums) {
		int forward = 1;
		int backward = 1;
		vector<int> res(nums.size(), 1);
		// forward
		for (int i = 0; i < nums.size(); ++i) {
			int j = nums.size() - i - 1;
			res[i] *= forward;
			res[j] *= backward;
			forward *= nums[i];
			backward *= nums[j];
		}
		return res;
	}
};

int main() {
	int array[] = {1, 2, 3, 4};
	vector<int> nums(array, array + 4);

	Solution sol;
	vector<int> res = sol.productExceptSelf(nums);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
}