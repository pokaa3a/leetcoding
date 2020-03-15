#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int knightDialer(int N) {
		int total = 0;
		for (int i = 0; i <= 9; ++i) {
			total = (total + dial(i, N)) % 1000000007;
		}
		return total;
	}
private:
	map<pair<int, int>, int> dp;

	int dial(int k, int n) {
		if (n == 1) {
			return 1;
		}
		if (k == 3 || k == 6 || k == 9) k -= 2;		// symmentric
		if (dp.find(make_pair(k, n)) != dp.end()) return dp[make_pair(k, n)];

		int num = 0;
		switch (k) {
			case 0:
				num = (num + dial(4, n - 1)) % 1000000007;
				num = (num + dial(6, n - 1)) % 1000000007;
				break;
			case 1:
				num = (num + dial(6, n - 1)) % 1000000007;
				num = (num + dial(8, n - 1)) % 1000000007;
				break;
			case 2:
				num = (num + dial(7, n - 1)) % 1000000007;
				num = (num + dial(9, n - 1)) % 1000000007;
				break;
			case 4:
				num = (num + dial(0, n - 1)) % 1000000007;
				num = (num + dial(3, n - 1)) % 1000000007;
				num = (num + dial(9, n - 1)) % 1000000007;
				break;
			case 5:
				num = 0;
				break;
			case 7:
				num = (num + dial(2, n - 1)) % 1000000007;
				num = (num + dial(6, n - 1)) % 1000000007;
				break;
			case 8:
				num = (num + dial(1, n - 1)) % 1000000007;
				num = (num + dial(3, n - 1)) % 1000000007;
				break;
		}
		dp[make_pair(k, n)] = num % 1000000007;
		return dp[make_pair(k, n)];
	}
};

int main() {
	int input = 3;
	Solution sol;
	cout << sol.knightDialer(input) << endl;
}