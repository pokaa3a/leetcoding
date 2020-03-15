#include <iostream>
using namespace std;

class Solution {
public:
	int lastRemaining (int n) {
		if (n == 1) return 1;
		int t = n / 2 * 2 + 1;
		return 2 * lastRemaining_right(t - (t + 1) / 2);
	}

	int lastRemaining_right (int n) {
		return (n + 1) - lastRemaining(n);
	}
};

int main () {
	int n = 10;
	Solution sol;
	cout << sol.lastRemaining(n) << endl;
}