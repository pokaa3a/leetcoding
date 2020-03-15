#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int> &nums) {
		if (!nums.size()) return 0;
		int continuous = 1;
		int max_seq = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[i-1]) {
				continuous++;
			} else {
				continuous = 1;
			}
			max_seq = max(max_seq, continuous);
		}
		return max_seq;
	}
};

int main() {
	int array[] = {1, 3, 5, 4, 7};
	vector<int> nums(array, array+5);
	Solution sol;
	cout << sol.findLengthOfLCIS(nums) << endl;
}