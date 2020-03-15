#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int largest1BorderedSquare(vector<vector<int> >& grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		vector<vector<int> > hor(rows, vector<int>(cols, 0));
		vector<vector<int> > ver(rows, vector<int>(cols, 0));

		for (int r = 0; r < rows; ++r) {
			int cur_sum = 0;
			for (int c = 0; c < cols; ++c) {
				if (grid[r][c] == 0) cur_sum = 0;
				else cur_sum += 1;
				hor[r][c] = cur_sum;
			}
		}
		for (int c = 0; c < cols; ++c) {
			int cur_sum = 0;
			for (int r = 0; r < rows; ++r) {
				if (grid[r][c] == 0) cur_sum = 0;
				else cur_sum += 1;
				ver[r][c] = cur_sum;
			}
		}
		int cur_max = 0;
		for (int r = rows - 1; r >= 0; --r) {
			for (int c = cols - 1; c >= 0; --c) {
				computeSquare(r, c, hor, ver, cur_max);
			}
		}
		return cur_max * cur_max;
	}
private:
	void computeSquare(int r, int c, vector<vector<int> >& hor, vector<vector<int> >& ver, int& cur_max) {
		int len = min(hor[r][c], ver[r][c]);
		int l;
		for (l = len; l > cur_max; --l) {
			if (hor[r - l + 1][c] >= l && ver[r][c - l + 1] >= l) {
				cur_max = max(cur_max, l);
				break;
			}
		}
	}
};

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp_row(rows, vector<int>(cols, 0));
        vector<vector<int>> dp_col(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] > 0) {
                    dp_row[i][j] = (j - 1 < 0 ? 0 : dp_row[i][j - 1]) + 1;
                    dp_col[i][j] = (i - 1 < 0 ? 0 : dp_col[i - 1][j]) + 1;
                }
            }
        }
        int ans = 0;
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                int max_len = min(dp_row[i][j], dp_col[i][j]);
                for (int k = max_len; k >= 1; --k) {
                    if (dp_row[i - k + 1][j] >= k && dp_col[i][j - k + 1] >= k) {
                        ans = max(ans, k * k);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
	int row1[] = {1, 0, 0, 0};
	int row2[] = {0, 1, 1, 1};
	int row3[] = {0, 1, 1, 1};
	vector<vector<int> > grid;
	grid.push_back(vector<int>(row1, row1 + 4));
	grid.push_back(vector<int>(row2, row2 + 4));
	grid.push_back(vector<int>(row3, row3 + 4));
	Solution sol;
	cout << sol.largest1BorderedSquare(grid) << endl;
}