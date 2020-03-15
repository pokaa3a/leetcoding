#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		deque<int> dq;
		vector<int> res;

		for(int i = 0; i < nums.size(); ++i) {
			while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
			dq.push_back(nums[i]);
			if (i >= k - 1) {
				res.push_back(dq.front());
				if (nums[i - k + 1] == dq.front()) dq.pop_front();
			}
		}
		return res;
	}
};

int main() {
	int array[] = {1, 3, -1, -3, 5, 3, 6, 7};
	vector<int> nums(array, array + 8);
	int k = 3;

	Solution sol;
	vector<int> res = sol.maxSlidingWindow(nums, k);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}

}