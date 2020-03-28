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
    int countSquares(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > v(m, vector<int>(n, 0)), h(m, vector<int>(n, 0)), d(m, vector<int>(n, 0));

        int ans = 0;
        for (int r = 0; r < m; r++) {
        	for (int c = 0; c < n; c++) {
        		if (matrix[r][c] == 1) {
        			v[r][c] = (r == 0 ? 0 : v[r - 1][c]) + 1;
        			h[r][c] = (c == 0 ? 0 : h[r][c - 1]) + 1;
        			d[r][c] = min((r == 0 || c == 0 ? 0 : d[r - 1][c - 1]) + 1, min(v[r][c], h[r][c]));
        			ans += d[r][c];
        		}
        	}
        }
        return ans;
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