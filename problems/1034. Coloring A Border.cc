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
	set<pair<int, int> > visited;
	int rows;
	int cols;
public:
    vector<vector<int> > colorBorder(vector<vector<int> >& grid, int r0, int c0, int color) {
        rows = grid.size();
        cols = grid[0].size();
        int ori_color = grid[r0][c0];
        dfs(grid, r0, c0, ori_color, color);
        return grid;
    }
    void dfs(vector<vector<int> >& grid, int r, int c, int ori_color, int color) {
    	bool isBorder = false;
    	visited.insert(make_pair(r, c));

    	// top
    	if (r == 0) {
    		isBorder = true;
    	} else {
    		if (visited.count(make_pair(r - 1, c)) == 0) {
    			if (grid[r - 1][c] != ori_color) isBorder = true;
    			else dfs(grid, r - 1, c, ori_color, color);
    		} 
    	}
    	// left
    	if (c == 0) {
    		isBorder = true;
    	} else {
    		if (visited.count(make_pair(r, c - 1)) == 0) {
    			if (grid[r][c - 1] != ori_color) isBorder = true;
    			else dfs(grid, r, c - 1, ori_color, color);
    		}
    	}
    	// bot
    	if (r == rows - 1) {
    		isBorder = true;
    	} else {
    		if (visited.count(make_pair(r + 1, c)) == 0) {
    			if (grid[r + 1][c] != ori_color) isBorder = true;
    			else dfs(grid, r + 1, c, ori_color, color);
    		}
    	}
    	// right
    	if (c == cols - 1) {
    		isBorder = true;
    	} else {
    		if (visited.count(make_pair(r, c + 1)) == 0) {
    			if (grid[r][c + 1] != ori_color) isBorder = true;
    			else dfs(grid, r, c + 1, ori_color, color);
    		}
    	}

    	if (isBorder) grid[r][c] = color;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	const int rows = 3, cols = 3;
	int r0 = 1, c0 = 1, color = 2;
	int g[rows][cols] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(g[r], g[r] + cols));
	}
	vector<vector<int> > res = sol.colorBorder(grid, r0, c0, color);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}