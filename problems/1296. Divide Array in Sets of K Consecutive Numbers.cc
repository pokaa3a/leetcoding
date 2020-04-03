#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool isPossibleDivide(vector<int>& nums, int k) {
		map<int, int> freq;
		for (int n : nums) {
			freq[n]++;
		}

		for (auto num : freq) {
			if (num.second == 0) continue;
			for (int x = num.first; x < num.first + k; x++) {
				if (freq.find(x) == freq.end() || freq[x] < num.second) return false;
				freq[x] -= num.second;
			}
		}
		return true;
	}
};

// class Solution {
// public:
// 	bool isPossibleDivide(vector<int>& nums, int k) {
// 		vector<int> count(k, 0);
// 		for (auto n : nums) {
// 			count[n % k]++;
// 		}
// 		return equal(count.begin() + 1, count.end(), count.begin());
// 	}
// };

int main() {
	vector<int> nums = {3,3,2,2,1,1};
	int k = 3;
	Solution sol;
	cout << sol.isPossibleDivide(nums, k) << endl;
}