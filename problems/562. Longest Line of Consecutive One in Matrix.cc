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
    int longestLine(vector<vector<int> >& M) {
        int m = M.size(), n = m > 0 ? M[0].size() : 0;
        if (m == 0 || n == 0) return 0;

        vector<vector<int> > h(m, vector<int>(n, 0)), v(m, vector<int>(n, 0)), dg(m, vector<int>(n, 0)), adg(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (M[i][j] == 0) continue;

        		// h
        		h[i][j] = (i == 0 ? 0 : h[i - 1][j]) + 1;

        		// v
        		v[i][j] = (j == 0 ? 0 : v[i][j - 1]) + 1;

        		// dg
        		dg[i][j] = (i == 0 || j == 0 ? 0 : dg[i - 1][j - 1]) + 1;

        		// adg
        		adg[i][j] = (i == 0 || j == n - 1 ? 0 : adg[i - 1][j + 1]) + 1;

        		ans = max(ans, h[i][j]);
        		ans = max(ans, v[i][j]);
        		ans = max(ans, dg[i][j]);
        		ans = max(ans, adg[i][j]);
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