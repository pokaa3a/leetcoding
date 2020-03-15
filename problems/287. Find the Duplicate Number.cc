#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int> &nums) {
		int slow = nums[0], fast = nums[nums[0]];
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};

int main() {
	int array[] = {1, 3, 4, 2, 2};
	vector<int> nums(array, array + 5);
	Solution sol;
	cout << sol.findDuplicate(nums);
}