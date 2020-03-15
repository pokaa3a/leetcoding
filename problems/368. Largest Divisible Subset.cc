#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int> &nums) {
		vector<int> T(nums.size(), 0);
		vector<int> parent(nums.size(), 0);
		int m = 0;
		int mi = 0;
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 0; --i) {
			for (int j = i; j < nums.size(); ++j) {
				if (nums[j] % nums[i] == 0 && T[i] <= T[j]) {
					T[i] = T[j] + 1;
					parent[i] = j;

					if (T[i] > m) {
						m = T[i];
						mi = i;
					}
				}
			}
		}

		vector<int> result;
		for (int i = 0; i < m; ++i) {
			result.push_back(nums[mi]);
			mi = parent[mi];
		}
		return result;
	}
};

int main() {
	int array[] = {1, 2, 4, 8};
	vector<int> nums(array, array + 4);

	Solution sol;
	vector<int> res = sol.largestDivisibleSubset(nums);
	for (int i = 0; i < res.size(); ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}