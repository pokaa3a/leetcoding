#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int findMaximumXOR(vector<int> &nums) {
		int maximum = 0;
		int mask = 0;
		
		for (int i = 31; i >= 0; --i) {
			mask |= 1 << i;
			set<int> prefix;

			for (int j = 0; j < nums.size(); ++j) {
				prefix.insert(nums[j] & mask);
			}
			int potential_max = maximum | (1 << i);

			for (set<int>::iterator it = prefix.begin(); it != prefix.end(); ++it) {
				if (prefix.count(*it ^ potential_max)) {
					maximum = potential_max;
					break;
				}
			}
		}
		return maximum;
	}
};

int main() {
	int array[] = {3, 10, 5, 25, 2, 8};
	vector<int> nums(array, array + 6);

	Solution sol;
	cout << sol.findMaximumXOR(nums) << endl;
}