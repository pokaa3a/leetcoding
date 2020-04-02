#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	bool judgePoint24(vector<int>& nums) {
		vector<double> v(nums.begin(), nums.end());
		return judge(v);
	}
	bool judge(vector<double>& nums) {
		if (nums.size() == 1) return fabs(nums[0] - 24.0) < 1e-3;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i == j) continue;
				vector<double> v;
				for (int k = 0; k < nums.size(); k++) {
					if (k != i && k != j) {
						v.push_back(nums[k]);
					}
				}
				// +
				v.push_back(nums[i] + nums[j]);
				if (judge(v)) return true;
				v.pop_back();
				// -
				v.push_back(nums[i] - nums[j]);
				if (judge(v)) return true;
				v.pop_back();
				// *
				v.push_back(nums[i] * nums[j]);
				if (judge(v)) return true;
				v.pop_back();
				// /
				v.push_back(nums[i] / nums[j]);
				if (judge(v)) return true;
			}
		}
		return false;
	}
};

int main() {
	Solution sol;
	vector<int> nums = {1, 2, 1, 2};
	cout << sol.judgePoint24(nums) << endl;
}