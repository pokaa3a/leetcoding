#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int stoneGameII(vector<int>& piles) {
		vector<vector<int> > dp(101, vector<int>(201, -1));

		int left_stones = 0;
		for (int i = 0; i < piles.size(); ++i) {
			left_stones += piles[i];
		}
		return compute(0, 1, dp, piles, left_stones);
	}
private:
	int compute(int start, int m, vector<vector<int> >& dp, vector<int>& piles, int left_stones) {
		if (dp[start][m] != -1) return dp[start][m];
		// if (start == piles.size()) return 0;

		int lim = min((int)piles.size() - 1, start + 2 * m - 1);
		int taken = 0, res = 0;
		for (int x = 1; start + x - 1 <= lim; ++x) {
			taken += piles[start + x - 1];
			res = max(res, left_stones - compute(start + x, max(m, x), dp, piles, left_stones - taken));
		}
		dp[start][m] = res;
		return res;
	}
};

int main() {
	int p[] = {2, 7, 9, 4, 4};
	vector<int> piles(p, p + 5);
	Solution sol;
	cout << sol.stoneGameII(piles) << endl;
}