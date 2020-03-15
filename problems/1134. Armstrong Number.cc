#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isArmstrong(int N) {
		int N_copy = N;
		vector<int> nums;
		while (N_copy) {
			nums.push_back(N_copy % 10);
			N_copy /= 10;
		}
		int k = nums.size();
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			res += pow(nums[i], k);
		}
		return res == N;
	}
};

int main() {
	Solution sol;
	cout << sol.isArmstrong(123) << endl;
}