#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int> &nums) {
		// find out median
		int n = nums.size();
		nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
		int med = nums[n / 2];

		// three-way-partition but with virtual indexing
		int i = 0, j = 0, k = n - 1;
		while (j <= k) {
			int v_i = (2 * i + 1) % (n | 1);
			int v_j = (2 * j + 1) % (n | 1);
			int v_k = (2 * k + 1) % (n | 1);

			if (nums[v_j] > med) {
				swap(nums[v_j], nums[v_i]);
				i++;
				j++;
			} else if (nums[v_j] < med) {
				swap(nums[v_j], nums[v_k]);
				k--;
			} else {
				j++;
			}
		}
	}
};

int main() {
	int array[] = {1, 1, 2, 1, 2, 2, 1};
	vector<int> nums = vector<int>(array, array + 7);

	Solution sol;
	sol.wiggleSort(nums);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}