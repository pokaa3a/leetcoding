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
    int minCost(vector<vector<int> >& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int> > count(m, vector<int>(n, INT_MAX));

		queue<pair<int, int> > q;
		int step = 0;
		explore(step, 0, 0, count, grid, q);
		while (!q.empty()) {
			step++;
			int q_size = q.size();
			for (int i = 0; i < q_size; ++i) {
				pair<int, int> p = q.front(); 
				q.pop();

				if (p.first == m - 1 && p.second == n - 1) break;

				for (int k = 1; k <= 3; ++k) {
					int next_sign = (grid[p.first][p.second] - 1 + k) % 4 + 1;

					int next_r = p.first, next_c = p.second;
					if (next_sign == 1) {
						next_c++;
					} else if (next_sign == 2) {
						next_c--;
					} else if (next_sign == 3) {
						next_r++;
					} else if (next_sign == 4) {
						next_r--;
					}
					if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n) {
						explore(step, next_r, next_c, count, grid, q);
					}
				}
			}
		}
		return count[m - 1][n - 1];
    }
    void explore(int step, int cur_r, int cur_c, vector<vector<int> >& count,
    			 vector<vector<int> >& grid, queue<pair<int, int> >& q) {
    	int m = grid.size(), n = grid[0].size();

    	while (true) {
    		if (count[cur_r][cur_c] != INT_MAX) break;
    		count[cur_r][cur_c] = step;
    		q.push(make_pair(cur_r, cur_c));

    		int sign = grid[cur_r][cur_c];
			int next_r = cur_r, next_c = cur_c;
			if (sign == 1) {
				next_c++;
			} else if (sign == 2) {
				next_c--;
			} else if (sign == 3) {
				next_r++;
			} else if (sign == 4) {
				next_r--;
			}
			if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n) {
				cur_r = next_r;
				cur_c = next_c;
			} else break;
    	}
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
	const int rows = 1;
	const int cols = 1;
	int arr[rows][cols] = {{4}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	cout << sol.minCost(grid) << endl;

	/* [String] */
	// string str = "";

}