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
    void setZeroes(vector<vector<int>>& matrix) {
    	int rows = matrix.size();
    	int cols = matrix[0].size();

    	bool col0 = false, row0 = false;
    	for (int r = 0; r < rows; r++) {
    		if (matrix[r][0] == 0) {
    			col0 = true;
    			break;
    		}
    	}
    	for (int c = 0; c < cols; c++) {
    		if (matrix[0][c] == 0) {
    			row0 = true;
    			break;
    		}
    	}
    	for (int r = 1; r < rows; r++) {
    		for (int c = 1; c < cols; c++) {
    			if (matrix[r][c] == 0) {
    				matrix[r][0] = 0;
    				matrix[0][c] = 0;
    			}
    		}
    	}
    	for (int r = 1; r < rows; r++) {
    		for (int c = 1; c < cols; c++) {
    			if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
    		}
    	}
    	if (row0) {
    		for (int c = 0; c < cols; c++) {
    			matrix[0][c] = 0;
    		}
    	}
    	if (col0) {
    		for (int r = 0; r < rows; r++) {
    			matrix[r][0] = 0;
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