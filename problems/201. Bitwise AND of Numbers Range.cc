#include <iostream>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int diffnum = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			diffnum++;
		}
		return n << diffnum;
	}
};

int main() {
	int m = 5, n = 7;
	Solution sol;

	cout << sol.rangeBitwiseAnd(m, n) << endl;
}