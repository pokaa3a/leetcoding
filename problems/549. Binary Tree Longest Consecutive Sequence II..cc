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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        longest(root, ans);
        return ans;
    }
    pair<int, int> longest(TreeNode* root, int& ans) {
    	if (!root) return make_pair(0, 0);

    	// pair: (inc, dec)
    	pair<int, int> left = longest(root->left, ans);
    	pair<int, int> right = longest(root->right, ans);

    	int left_inc = 0, left_dec = 0, right_inc = 0, right_dec = 0;
    	// left
    	if (root->left) {
    		if (root->left->val == root->val + 1) {
    			// increasing
    			left_inc = left.first;
    		} else if (root->left->val == root->val - 1) {
    			// decreasing
    			left_dec = left.second;
    		}
    	}

    	// right
    	if (root->right) {
    		if (root->right->val == root->val + 1) {
    			// increasing
    			right_inc = right.first;
    		} else if (root->right->val == root->val - 1) {
    			// decreasing
    			right_dec = right.second;
    		}
    	}
    	ans = max(ans, 1 + left_inc + right_dec);
    	ans = max(ans, 1 + left_dec + right_inc);
    	return make_pair(1 + max(left_inc, right_inc), 1 + max(left_dec, right_dec));
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	TreeNode* n1 = new TreeNode(2);
	TreeNode* n2 = new TreeNode(1);
	TreeNode* n3 = new TreeNode(3);

	n1->left = n2;
	n1->right = n3;

	cout << sol.longestConsecutive(n1) << endl;

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