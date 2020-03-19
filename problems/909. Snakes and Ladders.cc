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
    int snakesAndLadders(vector<vector<int> >& board) {
        int n = board.size();
        vector<int> cells(n * n + 1);

        int i = 1;
        bool go_right = true;
        for (int r = n - 1; r >= 0; r--) {
        	if (go_right) {
        		for (int c = 0; c < n; c++) {
        			cells[i++] = board[r][c];
        		}
        	} else {
        		for (int c = n - 1; c >= 0; c--) {
        			cells[i++] = board[r][c];
        		}
        	}
        	go_right = !go_right;
        }

        // BFS
        vector<int> shortest(n * n + 1, INT_MAX);
        shortest[1] = 0;
        queue<int> q;
        q.push(1);

        int steps = 1;
        while (!q.empty()) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; i++) {
        		int cur = q.front();
        		q.pop();
        		if (cur == n * n) return shortest[n * n];

        		for (int x = 1; x <= 6 && cur + x <= n * n; x++) {
        			if (cells[cur + x] == -1) {
        				if (shortest[cur + x] > steps) {
        					shortest[cur + x] = steps;
        					q.push(cur + x);
        				}
        			} else {
        				if (shortest[cells[cur + x]] > steps) {
        					shortest[cells[cur + x]] = steps;
        					q.push(cells[cur + x]);
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
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	/* [2-D vector] */
	const int rows = 8;
	const int cols = 8;
	int arr[rows][cols] = {{-1,-1,-1,46,47,-1,-1,-1},
						   {51,-1,-1,63,-1,31,21,-1},
						   {-1,-1,26,-1,-1,38,-1,-1},
						   {-1,-1,11,-1,14,23,56,57},
						   {11,-1,-1,-1,49,36,-1,48},
						   {-1,-1,-1,33,56,-1,57,21},
						   {-1,-1,-1,-1,-1,-1,2,-1},
						   {-1,-1,-1,8,3,-1,6,56}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	cout << sol.snakesAndLadders(grid) << endl;

	/* [String] */
	// string str = "";

}