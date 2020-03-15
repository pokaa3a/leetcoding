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

/* Solution */
const int MOD = 1000000007;
// class Solution {
// public:
//     int shortestPath(vector<vector<int> >& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<vector<int> > > dist(m, vector<vector<int> >(n, vector<int>(k + 1, INT_MAX)));

//         queue<vector<int> > q; // (i, j, path, # of elimations)
//         int a[] = {0, 0, 0, 0};
//         q.push(vector<int>(a, a + 4));
//         dist[0][0][0] = 0;

//         while (!q.empty()) {
//         	int q_size = q.size();
//         	for (int t = 0; t < q_size; ++t) {
//         		vector<int> p = q.front(); q.pop();
//         		int i = p[0], j = p[1], d = p[2], e = p[3];
//         		// cout << "(" << i << ", " << j << ")" << endl;

//         		// up
//         		if (i - 1 >= 0) {
//         			// cout << "up" << endl;
//         			if (grid[i - 1][j] == 0 && dist[i - 1][j][e] > d + 1) {
//         				dist[i - 1][j][e] = d + 1;
//         				int next[] = {i - 1, j, d + 1, e};
//         				q.push(vector<int>(next, next + 4));
//         			} else if (grid[i - 1][j] == 1 && e + 1 <= k && dist[i - 1][j][e + 1] > d + 1) {
//         				dist[i - 1][j][e + 1] = d + 1;
//         				int next[] = {i - 1, j, d + 1, e + 1};
//         				q.push(vector<int>(next, next + 4));
//         			}
//         		}
//         		// down
//         		if (i + 1 < m) {
//         			// cout << "down" << endl;
//         			if (grid[i + 1][j] == 0 && dist[i + 1][j][e] > d + 1) {
//         				dist[i + 1][j][e] = d + 1;
//         				int next[] = {i + 1, j, d + 1, e};
//         				q.push(vector<int>(next, next + 4));
//         			} else if (grid[i + 1][j] == 1 && e + 1 <= k && dist[i + 1][j][e + 1] > d + 1) {
//         				dist[i + 1][j][e + 1] = d + 1;
//         				int next[] = {i + 1, j, d + 1, e + 1};
//         				q.push(vector<int>(next, next + 4));
//         			}
//         		}
//         		// left
//         		if (j - 1 >= 0) {
//         			// cout << "left" << endl;
//         			if (grid[i][j - 1] == 0 && dist[i][j - 1][e] > d + 1) {
//         				dist[i][j - 1][e] = d + 1;
//         				int next[] = {i, j - 1, d + 1, e};
//         				q.push(vector<int>(next, next + 4));
//         			} else if (grid[i][j - 1] == 1 && e + 1 <= k && dist[i][j - 1][e + 1] > d + 1) {
//         				dist[i][j - 1][e + 1] = d + 1;
//         				int next[] = {i, j - 1, d + 1, e + 1};
//         				q.push(vector<int>(next, next + 4));
//         			}
//         		}
//         		// right
//         		if (j + 1 < n) {
//         			// cout << "right" << endl;
//         			if (grid[i][j + 1] == 0 && dist[i][j + 1][e] > d + 1) {
//         				dist[i][j + 1][e] = d + 1;
//         				int next[] = {i, j + 1, d + 1, e};
//         				q.push(vector<int>(next, next + 4));
//         			} else if (grid[i][j + 1] == 1 && e + 1 <= k && dist[i][j + 1][e + 1] > d + 1) {
//         				dist[i][j + 1][e + 1] = d + 1;
//         				int next[] = {i, j + 1, d + 1, e + 1};
//         				q.push(vector<int>(next, next + 4));
//         			}
//         		}
//         	}
//         }
//         int min_dist = *min_element(dist[m - 1][n - 1].begin(), dist[m - 1][n - 1].end());
//         return min_dist == INT_MAX ? -1 : min_dist;
//     }
// };

class Solution {
public:
    int shortestPath(vector<vector<int> >& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int> > obstacles(m, vector<int>(n, INT_MAX));
        obstacles[0][0] = 0;

        queue<vector<int> > q;
        int a[] = {0, 0, 0};
        q.push(vector<int>(a, a + 3));

        int steps = 0;
        while (!q.empty()) {
        	int q_size = q.size();
        	for (int t = 0; t < q_size; ++t) {
        		vector<int> p = q.front(); q.pop();
        		int i = p[0], j = p[1], e = p[2];
        		if (i == m - 1 && j == n - 1) return steps;
        		int directions[] = {0, 1, 0, -1, 0};
        		for (int s = 0; s < 4; ++s) {
        			int r = i + directions[s + 0], c = j + directions[s + 1];

        			if (r >= 0 && r < m && c >= 0 && c < n) {
        				int n_obs = grid[r][c] == 1 ? e + 1 : e;
        				if (n_obs > k) continue;
        				if (obstacles[r][c] == INT_MAX || obstacles[r][c] > n_obs) {
        					int next[] = {r, c, n_obs};
        					q.push(vector<int>(next, next + 3));
        					obstacles[r][c] = n_obs;
        				}
        			}
        		}
        	}
        	steps++;
        }
        return -1;
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
	const int rows = 3;
	const int cols = 3;
	int arr[rows][cols] = {{0,1,1}, {1,1,1}, {1,0,0}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	int k = 1;
	cout << sol.shortestPath(grid, k) << endl;

	/* [String] */
	// string str = "";

}