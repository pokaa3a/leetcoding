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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        store_bst_nodes(root, nodes);

        int n = nodes.size();
        return build_tree_util(nodes, 0, n - 1);
    }
    void store_bst_nodes(TreeNode* root, vector<TreeNode*>& nodes) {
    	if (!root) return;

    	store_bst_nodes(root->left, nodes);
    	nodes.push_back(root);
    	store_bst_nodes(root->right, nodes);
    }
    TreeNode* build_tree_util(vector<TreeNode*>& nodes, int start, int end) {
    	if (start > end) return NULL;

    	int mid = (start + end) / 2;
    	TreeNode* root = nodes[mid];

    	root->left = build_tree_util(nodes, start, mid - 1);
    	root->right = build_tree_util(nodes, mid + 1, end);

    	return root;
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