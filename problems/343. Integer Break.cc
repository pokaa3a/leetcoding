#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		vector<int> opm(n + 1, 0);
		opm[0] = 1;
		opm[1] = 1;
		for (int i = 2; i < n; ++i) {
			for (int j = 1; j <= i; ++j) {
				opm[i] = max(opm[i], j * opm[i - j]);
			}
		}
		opm[0] = 0;
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res = max(res, i * opm[n - i]);
		}
		return res;
	}
};

int main() {
	int n = 2;
	Solution sol;
	cout << sol.integerBreak(n) << endl;
}