#include <iostream>
using namespace std;

int first_bad = 1;

bool isBadVersion(int num) {
	return num >= first_bad;
};

class Solution {
public:
	int firstBadVersion(int n) {
		uint64_t left = 0, right = n - 1;
		while (right > left + 1) {
			int mid = (left + right) / 2;
			if (isBadVersion(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		for (int i = left; i <= right; ++i) {
			if (isBadVersion(i)) return i;
		}
		return n;
	}
};


int main() {
	int n = 5;
	Solution sol;
	cout << sol.firstBadVersion(n);
}