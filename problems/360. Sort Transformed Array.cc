#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int a_, b_, c_;
public:
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		a_ = a;
		b_ = b;
		c_ = c;

		vector<int> ans(nums.size(), 0);
		if (a == 0) {
			if (b >= 0) {
				for (int i = 0; i < nums.size(); i++) {
					ans[i] = quad(nums[i]);
				}
			} else {
				for (int i = 0; i < nums.size(); i++) {
					ans[nums.size() - i - 1] = quad(nums[i]);
				}
			}
			return ans;
		}

		int extreme = -b / (2 * a);
		int p1 = lower_bound(nums.begin(), nums.end(), extreme) - nums.begin() - 1;
		int p2 = p1 + 1;

		// cout << "p1 = " << p1 << " p2 = " << p2 << endl;

		if (a > 0) {
			int i = 0;
			while (p1 >= 0 && p2 < nums.size()) {
				if (quad(nums[p1]) <= quad(nums[p2])) {
					ans[i++] = quad(nums[p1--]);
				} else {
					ans[i++] = quad(nums[p2++]);
				}
			}
			while (p1 >= 0) {
				ans[i++] = quad(nums[p1--]);
			}
			while (p2 < nums.size()) {
				ans[i++] = quad(nums[p2++]);
			}
		} else {
			int i = nums.size() - 1;
			while (p1 >= 0 && p2 < nums.size()) {
				if (quad(nums[p1]) >= quad(nums[p2])) {
					ans[i--] = quad(nums[p1--]);
				} else {
					ans[i--] = quad(nums[p2++]);
				}
			}
			while (p1 >= 0) {
				ans[i--] = quad(nums[p1--]);
			}
			while (p2 < nums.size()) {
				ans[i--] = quad(nums[p2++]);
			}
		}
		return ans;
	}
	int quad(int x) {
		return a_ * x * x + b_ * x + c_;
	}
};

int main() {
	vector<int> nums = {-4, -2, 2, 4};
	Solution sol;
	int a = 1, b = 3, c = 5;
	vector<int> ans = sol.sortTransformedArray(nums, a, b, c);
	for (auto x : ans) cout << x << " ";
	cout << endl;
}