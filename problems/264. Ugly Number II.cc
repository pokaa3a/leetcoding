#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int idx_2 = 0, idx_3 = 0, idx_5 = 0;
		int factor_2 = 2, factor_3 = 3, factor_5 = 5;
		vector<int> nums(1, 1);
		for(int i = 1; i < n; ++i) {
			int next = min(factor_2, min(factor_3, factor_5));
			nums.push_back(next);
			if (factor_2 == next) {
				factor_2 = 2 * nums[++idx_2];
			} 
			if (factor_3 == next) {
				factor_3 = 3 * nums[++idx_3];
			} 
			if (factor_5 == next) {
				factor_5 = 5 * nums[++idx_5];
			}
		}
		return nums[n-1];
	}
};

int main() {
	Solution sol;
	cout << sol.nthUglyNumber(10);
}