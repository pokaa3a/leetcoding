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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int closedIsland(vector<vector<int> >& grid) {
    	int island_id = 2;
    	int num_islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
        	for (int j = 0; j < grid[i].size(); ++j) {
        		if (grid[i][j] == 0) {
        			if (bfs(island_id, i, j, grid)) {
        				island_id++;
        				num_islands++;
        			}
        		}
        	}
        }
        return num_islands;
    }
    bool bfs(int island_id, int r, int c, vector<vector<int> >& grid) {
    	int n = grid.size(), m = grid[0].size();
    	queue<pair<int, int> > q;
    	set<pair<int, int> > visited;
    	bool by_edge = (r == 0 || r == n - 1 || c == 0 || c == m - 1);

    	q.push(make_pair(r, c));
    	visited.insert(make_pair(r, c));
    	while (!q.empty()) {
    		int q_size = q.size();
    		for (int i = 0; i < q_size; ++i) {
    			int c_r = q.front().first;
    			int c_c = q.front().second;
    			q.pop();

    			if (c_r - 1 >= 0 && visited.count(make_pair(c_r - 1, c_c)) == 0 && grid[c_r - 1][c_c] == 0) {
    				if (c_r - 1 == 0) by_edge = true;
    				q.push(make_pair(c_r - 1, c_c));
    				visited.insert(make_pair(c_r - 1, c_c));
    			}
    			if (c_r + 1 < n && visited.count(make_pair(c_r + 1, c_c)) == 0 && grid[c_r + 1][c_c] == 0) {
    				if (c_r + 1 == n - 1) by_edge = true;
    				q.push(make_pair(c_r + 1, c_c));
    				visited.insert(make_pair(c_r + 1, c_c));
    			}
    			if (c_c - 1 >= 0 && visited.count(make_pair(c_r, c_c - 1)) == 0 && grid[c_r][c_c - 1] == 0) {
    				if (c_c - 1 == 0) by_edge = true;
    				q.push(make_pair(c_r, c_c - 1));
    				visited.insert(make_pair(c_r, c_c - 1));
    			}
    			if (c_c + 1 < m && visited.count(make_pair(c_r, c_c + 1)) == 0 && grid[c_r][c_c + 1] == 0) {
    				if (c_c + 1 == m - 1) by_edge = true;
    				q.push(make_pair(c_r, c_c + 1));
    				visited.insert(make_pair(c_r, c_c + 1));
    			}
    		}
    	}
    	for (set<pair<int, int> >::iterator it = visited.begin(); it != visited.end(); ++it) {
    		if (by_edge) {
    			grid[it->first][it->second] = -1;
    		} else {
    			grid[it->first][it->second] = island_id;
    		}
    	}
    	return !by_edge;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 7;
	const int cols = 7;
	int arr[rows][cols] = {{1,1,1,1,1,1,1}, 
						   {1,0,0,0,0,0,1}, 
						   {1,0,1,1,1,0,1},
						   {1,0,1,0,1,0,1},
						   {1,0,1,1,1,0,1},
						   {1,0,0,0,0,0,1},
						   {1,1,1,1,1,1,1}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.closedIsland(grid) << endl;

	/* [String] */
	// string str = "";

}