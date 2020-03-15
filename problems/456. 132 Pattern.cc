#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool find132pattern(vector<int> &nums) {
		stack<int> st;
		int second = INT_MIN;
		for (int i = nums.size() - 1; i >= 0; --i) {
			if (second > nums[i]) return true;
			while (!st.empty() && nums[i] > st.top()) {
				second = st.top();
				st.pop();
			}
			st.push(nums[i]);
		}
		return false;
	}
};

int main () {
	int array[] = {1, 2, 3, 4};
	vector<int> nums(array, array + 4);

	Solution sol;
	cout << sol.find132pattern(nums) << endl;
}