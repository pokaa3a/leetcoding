#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > pacificAtlantic(vector<vector<int> > &matrix) {
		vector<vector<int> > ans;
		int m = matrix.size();
		if (!m) return ans;
		int n = matrix[0].size();
		
		// water map:
		// -1: undiscovered
		// 1: can reach ocean
		// 0: cannot reach ocean
		vector<vector<int> > pacific(m, vector<int>(n, 0));
		vector<vector<int> > atlantic(m, vector<int>(n, 0));

		// Pacific ocean:
		//   top edge:
		for (int i = 0; i < n; ++i) {
			pacific[0][i] = 1;
		}
		//   left edge:
		for (int i = 0; i < m; ++i) {
			pacific[i][0] = 1;
		}

		// Atlantic ocean:
		//   bottom edge:
		for (int i = 0; i < n; ++i) {
			atlantic[m - 1][i] = 1;
		}
		//   right edge:
		for (int i = 0; i < m; ++i) {
			atlantic[i][n - 1] = 1;
		}

		// Walk through entire matrix
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (canReachOcean(matrix, pacific, i, j) && canReachOcean(matrix, atlantic, i, j)) {
					int a[] = {i, j};
					ans.push_back(vector<int>(a, a + 2));
				}
			}
		}
		return ans;
	}
private:
	bool canReachOcean(vector<vector<int> > &matrix, vector<vector<int> > &water_map, int i, int j) {
		if (water_map[i][j] == 1) {
			return true;
		} else if (water_map[i][j] == -1) {
			return false;
		}
		
		int m = matrix.size();
		int n = matrix[0].size();

		water_map[i][j] = -1;
		bool top = (i - 1) >= 0 && (matrix[i][j] >= matrix[i - 1][j]) && canReachOcean(matrix, water_map, i - 1, j);
		bool lft = (j - 1) >= 0 && (matrix[i][j] >= matrix[i][j - 1]) && canReachOcean(matrix, water_map, i, j - 1);
		bool bot = (i + 1) <  m && (matrix[i][j] >= matrix[i + 1][j]) && canReachOcean(matrix, water_map, i + 1, j);
		bool rht = (j + 1) <  n && (matrix[i][j] >= matrix[i][j + 1]) && canReachOcean(matrix, water_map, i, j + 1);
		water_map[i][j] = 0;
		if (top || lft || bot || rht) {
			water_map[i][j] = 1;
		}
		return water_map[i][j];
	};
};


int main () {
	int row0[] = {1, 2, 2, 3, 5};
	int row1[] = {3, 2, 3, 4, 4};
	int row2[] = {2, 4, 5, 3, 1};
	int row3[] = {6, 7, 1, 4, 5};
	int row4[] = {5, 1, 1, 2, 4};

	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(row0, row0 + 5));
	matrix.push_back(vector<int>(row1, row1 + 5));
	matrix.push_back(vector<int>(row2, row2 + 5));
	matrix.push_back(vector<int>(row3, row3 + 5));
	matrix.push_back(vector<int>(row4, row4 + 5));

	Solution sol;
	vector<vector<int> > ans = sol.pacificAtlantic(matrix);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i][0] << ", " << ans[i][1] << endl;
	}
}
