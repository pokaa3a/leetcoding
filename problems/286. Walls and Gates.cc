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
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rooms.size(); i++) {
        	for (int j = 0; j < rooms[i].size(); j++) {
        		if (rooms[i][j] == 0) {
        			q.push(make_pair(i, j));
        		}
        	}
        }

        while (!q.empty()) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; i++) {
        		pair<int, int> cur = q.front();
        		q.pop();
        		int r = cur.first, c = cur.second;

        		int paths[] = {-1, 0, 1, 0, -1};
        		for (int j = 0; j < 4; j++) {
        			int next_r = r + paths[j], next_c = c + paths[j + 1];
        			if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n &&
        				rooms[next_r][next_c] != -1 &&
        				rooms[r][c] + 1 < rooms[next_r][next_c]) {
        				rooms[next_r][next_c] = rooms[r][c] + 1;
        				q.push(make_pair(next_r, next_c));
        			}
        		}
        	}
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