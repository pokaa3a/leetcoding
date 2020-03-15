#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		map<int, long int> buckets;
		for (int i = 0; i < nums.size(); ++i) {
			long int bucketNum = nums[i];
			long int offset = 0;
			if (t != 0) {
				bucketNum = nums[i] / t;
				offset = 1;
			}

			for (long int idx = bucketNum - offset; idx <= bucketNum + offset; ++idx) {
				if (buckets.count(idx) && abs(buckets[idx] - nums[i]) <= t) return true;
			}

			buckets[bucketNum] = nums[i];
			if (buckets.size() > k) {
				if (t != 0) {
					buckets.erase(nums[i - k] / t);
				} else {
					buckets.erase(nums[i - k]);
				}
			}
		}
		return false;
	}
};

int main() {
	int array[] = {-1, 2147483647};
	int k = 1;
	int t = 2147483647;

	vector<int> nums(array, array + 2);
	Solution sol;
	std::cout << sol.containsNearbyAlmostDuplicate(nums, k, t);
}