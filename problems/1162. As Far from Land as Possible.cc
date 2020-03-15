#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int maxDistance(vector<vector<int> >& grid) {
		queue<pair<int, int> > q;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 1 && isByWater(i, j, grid)) q.push(make_pair(i, j));
			}
		}

		int rows = grid.size(), cols = grid[0].size(), dist = 0;
		while (!q.empty()) {
			dist++;
			int q_size = q.size();
			for (int i = 0; i < q_size; ++i) {
				pair<int, int> cur = q.front();
				q.pop();
				int r = cur.first;
				int c = cur.second;

				// top
				if (r - 1 >= 0 && grid[r - 1][c] == 0) {
					grid[r - 1][c] = 1;
					q.push(make_pair(r - 1, c));
				};
				// bot
				if (r + 1 < rows && grid[r + 1][c] == 0) {
					grid[r + 1][c] = 1;
					q.push(make_pair(r + 1, c));
				}
				// left
				if (c - 1 >= 0 && grid[r][c - 1] == 0) {
					grid[r][c - 1] = 1;
					q.push(make_pair(r, c - 1));
				}
				// right
				if (c + 1 < cols && grid[r][c + 1] == 0) {
					grid[r][c + 1] = 1;
					q.push(make_pair(r, c + 1));
				}
			}
		}
		return dist - 1;
	}
private:
	bool isByWater(int r, int c, vector<vector<int> >& grid) {
		int rows = grid.size(), cols = grid[0].size();
		// top
		if (r - 1 >= 0 && grid[r - 1][c] == 0) return true;
		// bot
		if (r + 1 < rows && grid[r + 1][c] == 0) return true;
		// left
		if (c - 1 >= 0 && grid[r][c - 1] == 0) return true;
		// right
		if (c + 1 < cols && grid[r][c + 1] == 0) return true;
		return false;
	}
};

class Solution {
public:
    int rows, cols;
    int maxDistance(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int> > q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                }
            }
        }
        int dist = -1;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                pair<int, int> cell = q.front(); q.pop();
                fill_water(cell, dist, grid, q);
            }
            dist--;
        }
        int ans = -1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = grid[i][j] < 0 ? max(ans, -grid[i][j]) : ans;;
            }
        }
        return ans;
    }
    void fill_water(pair<int, int> cell, int dist, vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        int r = cell.first;
        int c = cell.second;
        if (r - 1 >= 0 && grid[r - 1][c] == 0) {
            grid[r - 1][c] = dist;
            q.push(make_pair(r - 1, c));
        }
        if (r + 1 < rows && grid[r + 1][c] == 0) {
            grid[r + 1][c] = dist;
            q.push(make_pair(r + 1, c));
        }
        if (c - 1 >= 0 && grid[r][c - 1] == 0) {
            grid[r][c - 1] = dist;
            q.push(make_pair(r, c - 1));
        }
        if (c + 1 < cols && grid[r][c + 1] == 0) {
            grid[r][c + 1] = dist;
            q.push(make_pair(r, c + 1));
        }
    }
};

int main() {
	int row1[] = {1, 0, 1};
	int row2[] = {0, 0, 0};
	int row3[] = {1, 0, 1};
	vector<vector<int> > grid;
	grid.push_back(vector<int>(row1, row1 + 3));
	grid.push_back(vector<int>(row2, row2 + 3));
	grid.push_back(vector<int>(row3, row3 + 3));

	Solution sol;
	cout << sol.maxDistance(grid) << endl;
}