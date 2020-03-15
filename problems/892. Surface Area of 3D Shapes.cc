#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int surfaceArea(vector<vector<int> > &grid) {
		int rows = grid.size();
		if (!rows) return 0;
		int cols = grid[0].size();
		if (!cols) return 0;

		int area = 0;
		for (int r = 0; r < grid.size(); ++r) {
			for (int c = 0; c < grid[r].size(); ++c) {
				// left
				if (c == 0) area += grid[r][c];
				else area += max(grid[r][c] - grid[r][c - 1], 0);
				// top
				if (r == 0) area += grid[r][c];
				else area += max(grid[r][c] - grid[r - 1][c], 0);
				// right
				if (c == cols - 1) area += grid[r][c];
				else area += max(grid[r][c] - grid[r][c + 1], 0);
				// down
				if (r == rows - 1) area += grid[r][c];
				else area += max(grid[r][c] - grid[r + 1][c], 0);

				area += grid[r][c] ? 2 : 0;
			}
		}
		return area;
	}
};

int main() {
	int row0_array[] = {1, 1, 1};
	vector<int> row0(row0_array, row0_array + 3);
	int row1_array[] = {1, 0, 1};
	vector<int> row1(row1_array, row1_array + 3);
	int row2_array[] = {1, 1, 1};
	vector<int> row2(row2_array, row2_array + 3);

	vector<vector<int> > grid;
	grid.push_back(row0);
	grid.push_back(row1);
	grid.push_back(row2);

	Solution sol;
	cout << sol.surfaceArea(grid);
}