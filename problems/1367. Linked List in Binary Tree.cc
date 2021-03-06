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
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> list;
        ListNode* cur = head;
        while (cur) {
        	list.push_back(cur->val);
        	cur = cur->next;
        }
        return dfs(root, list);
    }
    bool dfs(TreeNode* root, vector<int>& list) {
    	if (!root) return false;

    	return explore(root, 0, list) | dfs(root->left, list) | dfs(root->right, list);
    }
    bool explore(TreeNode* root, int idx, vector<int>& list) {
    	if (idx == list.size()) return true;
    	if (!root) return false;

    	if (root->val == list[idx]) {
    		return explore(root->left, idx + 1, list) | explore(root->right, idx + 1, list);
    	}
    	return false;
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