#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
private:
	int ans;
	int rows;
	int cols;
	int num_blocks;
public:
    int uniquePathsIII(vector<vector<int> >& grid) {
        ans = 0;
        num_blocks = 0;
        rows = grid.size();
        cols = grid[0].size();

        int r0, c0;
        for (int i = 0; i < grid.size(); ++i) {
        	for (int j = 0; j < grid[0].size(); ++j) {
        		if (grid[i][j] == 1) {
        			r0 = i;
        			c0 = j;
        		} else if (grid[i][j] == -1) num_blocks++;
        	}
        }

        dfs(r0, c0, grid, 0);
        return ans;
    }
    void dfs(int r, int c, vector<vector<int> >& grid, int steps) {
    	if (r < 0 || r >= rows || c < 0 || c >= cols) return;
    	if (grid[r][c] == -1) return;

    	if (grid[r][c] == 2) {
    		if (rows * cols - num_blocks - 1 == steps) {
    			ans++;
    		}
    		return;
    	}
    	grid[r][c] = -1;
    	dfs(r - 1, c, grid, steps + 1);
    	dfs(r, c - 1, grid, steps + 1);
    	dfs(r + 1, c, grid, steps + 1);
    	dfs(r, c + 1, grid, steps + 1);
    	grid[r][c] = 0;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int g[3][4] = {{1,0,0,0}, {0,0,0,0}, {0,0,0,2}};
	vector<vector<int> > grid;
	grid.push_back(vector<int>(g[0], g[0] + 4));
	grid.push_back(vector<int>(g[1], g[1] + 4));
	grid.push_back(vector<int>(g[2], g[2] + 4));

	cout << sol.uniquePathsIII(grid) << endl;
}