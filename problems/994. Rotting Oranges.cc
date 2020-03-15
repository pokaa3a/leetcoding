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
public:
    int orangesRotting(vector<vector<int> >& grid) {
        queue<pair<int, int> > q;
        int rows = grid.size(), cols = grid[0].size();
        int n_fresh = 0;
        for (int i = 0; i < grid.size(); ++i) {
        	for (int j = 0; j < grid[i].size(); ++j) {
        		if (grid[i][j] == 1) n_fresh++;
        		else if (grid[i][j] == 2) {
        			q.push(make_pair(i, j));
        		}
        	}
        }
        
        int minutes = 0;
        while (!q.empty() && n_fresh > 0) {
        	int q_size = q.size();
        	minutes++;
        	for (int i = 0; i < q_size; ++i) {
        		pair<int, int> p = q.front(); q.pop();
        		int r = p.first, c = p.second;
        		
        		// top
        		if (r - 1 >= 0 && grid[r - 1][c] == 1) {
        			q.push(make_pair(r - 1, c));
        			grid[r - 1][c] = 2;
        			n_fresh--;
        		}
        		// left
        		if (c - 1 >= 0 && grid[r][c - 1] == 1) {
        			q.push(make_pair(r, c - 1));
        			grid[r][c - 1] = 2;
        			n_fresh--;
        		}
        		// bot
        		if (r + 1 < rows && grid[r + 1][c] == 1) {
        			q.push(make_pair(r + 1, c));
        			grid[r + 1][c] = 2;
        			n_fresh--;
        		}
        		// right
        		if (c + 1 < cols && grid[r][c + 1] == 1) {
        			q.push(make_pair(r, c + 1));
        			grid[r][c + 1] = 2;
        			n_fresh--;
        		}
        	}
        }
        return n_fresh == 0 ? minutes : -1;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int g[1][2] = {{0,2}};
	vector<vector<int> > grid;
	for (int i = 0; i < 1; ++i) {
		grid.push_back(vector<int>(g[i], g[i] + 2));
	}
	cout << sol.orangesRotting(grid) << endl;


}