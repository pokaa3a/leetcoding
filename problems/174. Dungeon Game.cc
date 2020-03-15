#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int> >& dungeon) {
		int M = dungeon.size();
		int N = dungeon[0].size();
		vector<vector<int> > dp(M + 1, vector<int>(N + 1, INT_MAX));
		dp[M][N-1] = 1;

		// filling dp
		for (int i = M - 1; i >= 0; --i) {
			for (int j = N - 1; j >= 0; --j) {
				dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j] > 0 ? min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j] : 1;
			}
		}
		return dp[0][0];
	}
};

int main() {
	int row1[] = {-2, -3, 3};
	int row2[] = {-5, -10, 1};
	int row3[] = {10, 30, -5};

	vector<vector<int> > dungeon;
	dungeon.push_back(vector<int>(row1, row1+3));
	dungeon.push_back(vector<int>(row2, row2+3));
	dungeon.push_back(vector<int>(row3, row3+3));

	Solution sol;
	cout << sol.calculateMinimumHP(dungeon);
}