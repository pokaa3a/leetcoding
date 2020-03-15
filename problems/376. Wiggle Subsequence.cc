#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int wiggleMaxLength(vector<int> &nums) {
		if (nums.size() <= 1) return nums.size();
		int ans = 1;

		int i = 1;
		bool gradient_pre;
		// search for the first gradient
		while (i < nums.size()) {
			if (nums[i] > nums[i - 1]) {
				gradient_pre = true;
				ans++;
				break;
			} else if (nums[i] < nums[i - 1]) {
				gradient_pre = false;
				ans++;
				break;
			}
			i++;
		}
		for (; i < nums.size(); ++i) {
			if (nums[i] != nums[i - 1]) {
				bool gradient_cur = nums[i] > nums[i - 1];
				ans += gradient_cur ^ gradient_pre;
				gradient_pre = gradient_cur;
			}
		}
		return ans;
	}
};

int main() {
	int array[] = {1,1,1};
	vector<int> nums = vector<int>(array, array + 3);

	Solution sol;
	cout << sol.wiggleMaxLength(nums) << endl;
}