#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int trap(vector<int> &height) {
		if (height.size() < 2) return 0;
		
		vector<int> left_max(height.size(), 0);
		vector<int> right_max(height.size(), 0);

		left_max[0] = 0;
		for (int i = 1; i < height.size(); i++) {
			left_max[i] = max(left_max[i - 1], height[i - 1]);
		}
		right_max[height.size() - 1] = 0;
		for (int i = height.size() - 2; i >= 0; --i) {
			right_max[i] = max(right_max[i + 1], height[i + 1]);
		}

		int water = 0;
		for (int i = 0; i < height.size(); ++i) {
			water += max(min(left_max[i], right_max[i]) - height[i], 0);
		}
		return water;
	}
};

int main() {
	int array[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	vector<int> height(array, array + 12);

	Solution sol;
	cout << sol.trap(height) << endl;
}