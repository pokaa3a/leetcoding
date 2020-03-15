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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        // traverse first tree
        set<int> s;
        dfs(root1, s);
        return find_sum(root2, s, target);
    }
    void dfs(TreeNode* root, set<int>& s) {
    	if (!root) return;
    	s.insert(root->val);
    	dfs(root->left, s);
    	dfs(root->right, s);
    }
    bool find_sum(TreeNode* root, set<int>& s, int target) {
    	if (!root) return false;
    	if (s.count(target - root->val) > 0) return true;
    	if (find_sum(root->left, s, target)) return true;
    	if (find_sum(root->right, s, target)) return true;
    	return false;
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