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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return vector<vector<int>>();
        if (root->val == sum && !root->left && !root->right) return vector<vector<int>>(1, vector<int>(1, sum));
        
        vector<vector<int>> ans;
        vector<vector<int>> left_paths = pathSum(root->left, sum - root->val);
        for (int i = 0; i < left_paths.size(); ++i) {
            left_paths[i].insert(left_paths[i].begin(), root->val);
            ans.push_back(left_paths[i]);
        }
        
        vector<vector<int>> right_paths = pathSum(root->right, sum - root->val);
        for (int i = 0; i < right_paths.size(); ++i) {
            right_paths[i].insert(right_paths[i].begin(), root->val);
            ans.push_back(right_paths[i]);
        }
        return ans;
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