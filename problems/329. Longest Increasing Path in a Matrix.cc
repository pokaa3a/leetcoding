#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));
		int ans = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, dfs(matrix, dp, i, j));
			}
		}
		return ans;
	}
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {
		if (dp[r][c] > 0) return dp[r][c];

		int m = matrix.size(), n = matrix[0].size();
		int dirs[] = {-1, 0, 1, 0, -1};

		// explore
		dp[r][c] = 1;
		for (int k = 0; k < 4; k++) {
			int i = dirs[k], j = dirs[k + 1];
			if (r + i >= 0 && r + i < m && c + j >= 0 && c + j < n &&
				matrix[r + i][c + j] > matrix[r][c]) {
				dp[r][c] = max(dp[r][c], 1 + dfs(matrix, dp, r + i, c + j));
			}
		}
		return dp[r][c];
	}
};

int main() {
	vector<vector<int>> nums = {{3,4,5},{3,2,6},{2,2,1}};
	Solution sol;
	cout << sol.longestIncreasingPath(nums) << endl;
}