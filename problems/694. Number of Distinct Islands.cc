#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinctIslands(vector<vector<int> > &grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		set<string> islands;

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (grid[i][j] == 1) {
					string island = BFS(grid, make_pair(i, j));
					islands.insert(island);
				}
			}
		}
		return islands.size();
	}
public:
	string BFS(vector<vector<int> > &grid, pair<int, int> start) {
		int rows = grid.size();
		int cols = grid[0].size();

		string island;
		queue<pair<int, int> > q;
		q.push(start);
		grid[start.first][start.second] = 0;
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				pair<int, int> next = q.front();
				q.pop();
				island += "(" + to_string(next.first - start.first) + "," + to_string(next.second - start.second) + ")";

				// top
				if (next.first > 0) {
					if (grid[next.first - 1][next.second] == 1) {
						q.push(make_pair(next.first - 1, next.second));
						grid[next.first - 1][next.second] = 0;
					}
				}
				// right
				if (next.second < cols - 1) {
					if (grid[next.first][next.second + 1] == 1) {
						q.push(make_pair(next.first, next.second + 1));
						grid[next.first][next.second + 1] = 0;
					}
				}
				// left
				if (next.second > 0) {
					if (grid[next.first][next.second - 1] == 1) {
						q.push(make_pair(next.first, next.second - 1));
						grid[next.first][next.second - 1] = 0;
					}
				}
				// bot
				if (next.first < rows - 1) {
					if (grid[next.first + 1][next.second] == 1) {
						q.push(make_pair(next.first + 1, next.second));
						grid[next.first + 1][next.second] = 0;
					}
				}
			}
		}
		return island;
	}
};

int main () {
	int row0[] = {1, 1, 0, 1, 1};
	int row1[] = {1, 0, 0, 0, 0};
	int row2[] = {0, 0, 0, 0, 1};
	int row3[] = {1, 1, 0, 1, 1};
	vector<vector<int> > grid;
	grid.push_back(vector<int>(row0, row0 + 5));
	grid.push_back(vector<int>(row1, row1 + 5));
	grid.push_back(vector<int>(row2, row2 + 5));
	grid.push_back(vector<int>(row3, row3 + 5));

	Solution sol;
	cout << sol.numDistinctIslands(grid);

}