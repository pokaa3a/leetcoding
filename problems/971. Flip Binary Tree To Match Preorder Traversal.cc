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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int idx = 0;
        if (!traverse(root, idx, voyage, ans)) {
            return vector<int>(1, -1);
        }
        return ans;
    }
    bool traverse(TreeNode* root, int& idx, vector<int>& voyage, vector<int>& ans) {
        if (!root) return true;
        
        if (root->val != voyage[idx]) return false;
        if (root->right && root->left && root->right->val == voyage[idx + 1]) {
            swap(root->left, root->right);
            ans.push_back(root->val);
        }
        idx++;
        if (!traverse(root->left, idx, voyage, ans)) return false;
        if (!traverse(root->right, idx, voyage, ans)) return false;
        return true;
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