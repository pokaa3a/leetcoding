#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <list>
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> res(rows, vector<int>(cols, INT_MAX));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == 0) res[r][c] = 0;
                else {
                    if (r > 0) res[r][c] = min(res[r][c], res[r - 1][c] == INT_MAX ? INT_MAX : res[r - 1][c] + 1);
                    if (c > 0) res[r][c] = min(res[r][c], res[r][c - 1] == INT_MAX ? INT_MAX : res[r][c - 1] + 1);
                }
            }
        }
        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {
                if (r < rows - 1) {
                    res[r][c] = min(res[r][c], res[r + 1][c] == INT_MAX ? INT_MAX : res[r + 1][c] + 1);
                }
                if (c < cols - 1) {
                    res[r][c] = min(res[r][c], res[r][c + 1] == INT_MAX ? INT_MAX : res[r][c + 1] + 1);
                }
            }
        }
        return res;
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