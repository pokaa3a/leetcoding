#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// class Solution {
// public:
// 	int shortestPathBinaryMatrix(vector<vector<int> >& grid) {
// 		if (grid[0][0] == 1) return -1;
// 		int n = grid.size();
// 		if (n == 1) return 1;
// 		queue<pair<int, int> > q;

// 		q.push(make_pair(0, 0));
// 		grid[0][0] = 1;

// 		int shortest = 1;
// 		while (!q.empty()) {
// 			int q_size = q.size();
// 			shortest++;
// 			for (int k = 0; k < q_size; ++k) {
// 				pair<int, int> cur = q.front();
// 				q.pop();
// 				int r = cur.first, c = cur.second;

// 				for (int i = -1; i <= 1; ++i) {
// 					for (int j = -1; j <= 1; ++j) {
// 						if (r + i < 0 || r + i >= n || c + j < 0 || c + j >= n ) continue;
// 						if (grid[r + i][c + j] == 1) continue;
// 						if (r + i == n - 1 && c + j == n - 1) return shortest;
// 						q.push(make_pair(r + i, c + j));
// 						grid[r + i][c + j] = 1;
// 					}
// 				}
// 			}
// 		}
// 		return -1;
// 	}
// };

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int> >& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int> > q;
        int ans = 0;
        if (grid[0][0] == 0){
        	q.push(make_pair(0, 0));
        	grid[0][0] = 1;
        }
        while (!q.empty()) {
            int q_size = q.size();
            ans++;
            for (int i = 0; i < q_size; ++i) {
                pair<int, int> cur = q.front(); q.pop();
                int x = cur.first, y = cur.second;
                if (x == rows - 1 && y == cols - 1) return ans;
                
                for (int r = -1; r <= 1; ++r) {
                    for (int c = -1; c <= 1; ++c) {
                    	if (x + r >= 0 && x + r < rows &&
                    		y + c >= 0 && y + c < cols &&
                    		grid[x + r][x + c] == 0) {
                    		q.push(make_pair(x + r, y + c));
                    		grid[cur.first][cur.second] = 1;
                    	}
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
	int row1[] = {0, 1, 0, 1};
	int row2[] = {0, 1, 0, 1};
	int row3[] = {0, 0, 0, 1};
	int row4[] = {1, 0, 1, 0};
	vector<vector<int> > grid;
	grid.push_back(vector<int>(row1, row1 + 4));
	grid.push_back(vector<int>(row2, row2 + 4));
	grid.push_back(vector<int>(row3, row3 + 4));
	grid.push_back(vector<int>(row4, row4 + 4));

	Solution *sol = new Solution();
	cout << sol->shortestPathBinaryMatrix(grid) << endl;

}