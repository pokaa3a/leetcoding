#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();

		for(int start_idx = 0, count = 0; count < nums.size(); start_idx++) {
			int current_idx = start_idx;
			int prev = nums[start_idx];
			do {
				int next_idx = (current_idx + k) % nums.size();
				int temp = nums[next_idx];
				nums[next_idx] = prev;
				prev = temp;
				current_idx = next_idx;
				count++;
			} while (current_idx != start_idx);
		}
	}
};

class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
	}

	void reverse(vector<int>& nums, int start, int end) {
		while (start < end) {
			swap(nums[start++], nums[end--]);
		}
	}
};

class Solution3 {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

int main() {
	int array[] = {1,2,3,4,5,6,7};
	vector<int> nums(array, array+7);
	int k = 3;

	Solution3 sol;
	sol.rotate(nums, k);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}