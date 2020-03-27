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
    int maxSideLength(vector<vector<int> >& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int> > presum(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++) {
        	for (int c = 0; c < n; c++) {
        		presum[r][c] = mat[r][c] + 
        		               (r == 0 ? 0 : presum[r - 1][c]) + 
        		               (c == 0 ? 0 : presum[r][c - 1]) - 
        		               (r == 0 || c == 0 ? 0 : presum[r - 1][c - 1]);
        	}
        }

        int l = 1, ans = 0;
        for (int r = 0; r + l <= m; r++) {
        	for (int c = 0; c + l <= n; c++) {
        		while (r + l <= m && c + l <= n && square_sum(r, c, l, presum) <= threshold) {
        			ans = max(ans, l);
        			l++;
        		}
        	}
        }
        return ans;
    }
    int square_sum(int r, int c, int l, vector<vector<int> >& presum) {
    	return presum[r + l - 1][c + l - 1] - 
    	       (r == 0 ? 0 : presum[r - 1][c + l - 1]) - 
    	       (c == 0 ? 0 : presum[r + l - 1][c - 1]) +
    	       (r == 0 || c == 0 ? 0 : presum[r - 1][c - 1]);
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
	const int rows = 3;
	const int cols = 7;
	int arr[rows][cols] = {{1,1,3,2,4,3,2},
						   {1,1,3,2,4,3,2},
						   {1,1,3,2,4,3,2}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	int threshold = 4;
	cout << sol.maxSideLength(grid, threshold) << endl;

	/* [String] */
	// string str = "";

}