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
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<int> res = leaves(root);
        return res[1];
    }

    vector<int> leaves(TreeNode* root) {
    	vector<int> res(2, 0);
    	if (!root) {
    		return res;
    	}

    	vector<int> left = leaves(root->left);
    	int lv_left = left[0], sum_left = left[1];

    	vector<int> right = leaves(root->right);
    	int lv_right = right[0], sum_right = right[1];

    	if (lv_left == lv_right) {
    		res[0] = lv_left + 1;
    		res[1] = sum_left + sum_right;
    	} else {
    		res[0] = max(lv_left, lv_right) + 1;
    		res[1] = lv_left > lv_right ? sum_left : sum_right;
    	}

    	if (!root->left && !root->right) {
    		res[1] = root->val;
    	}
    	return res;
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