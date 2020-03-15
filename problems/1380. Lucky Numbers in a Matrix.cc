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
    vector<int> luckyNumbers (vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> row_mins, col_maxs;

        for (int r = 0; r < m; ++r) {
        	int mini = matrix[r][0], idx = 0;
        	for (int c = 0; c < n; ++c) {
        		if (matrix[r][c] < mini) {
        			mini = matrix[r][c];
        			idx = c;
        		}
        	}
        	row_mins.push_back(idx);
        }

        for (int c = 0; c < n; ++c) {
        	int maxi = matrix[0][c], idx = 0;
        	for (int r = 0; r < m; ++r) {
        		if (matrix[r][c] > maxi) {
        			maxi = matrix[r][c];
        			idx = r;
        		}
        	}
        	col_maxs.push_back(idx);
        }
        vector<int> ans;
        for (int r = 0; r < m; ++r) {
        	int c = row_mins[r];
        	if (col_maxs[c] == r) {
        		ans.push_back(matrix[r][c]);
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