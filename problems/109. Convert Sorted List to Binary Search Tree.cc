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
    ListNode* root;
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }
        root = head;
        return helper(0, n - 1);
    }
    TreeNode* helper(int lo, int hi) {
        if (lo > hi) return NULL;
        
        int mid = lo + (hi - lo) / 2;
        
        TreeNode* left = helper(lo, mid - 1);
        TreeNode* new_node = new TreeNode(root->val);
        root = root->next;
        TreeNode* right = helper(mid + 1, hi);
        new_node->left = left;
        new_node->right = right;
        return new_node;
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