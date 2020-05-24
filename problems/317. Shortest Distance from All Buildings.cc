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
#include <numeric>
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

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        
        int buildings = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    bfs(i, j, grid, dist);
                    buildings--;
                }
            }
        }
        int shortest = INT_MAX;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == buildings) shortest = min(shortest, dist[i][j]);
            }
        }
        return shortest == INT_MAX ? -1 : shortest;
    }
    void bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dist) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        visited[r][c] = true;
        
        int d = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                int r_cur = q.front().first;
                int c_cur = q.front().second;
                q.pop();
                
                dist[r_cur][c_cur] += d;
                grid[r_cur][c_cur]--;
                
                int dirs[] = {-1, 0, 1, 0, -1};
                for (int k = 0; k < 4; k++) {
                    int r_next = r_cur + dirs[k];
                    int c_next = c_cur + dirs[k + 1];
                    if (r_next >= 0 && r_next < rows &&
                        c_next >= 0 && c_next < cols &&
                        !visited[r_next][c_next] &&
                        grid[r_next][c_next] < 1) {
                        visited[r_next][c_next] = true;
                        q.push(make_pair(r_next, c_next));
                    }
                }
            }
            d++;
        }
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}