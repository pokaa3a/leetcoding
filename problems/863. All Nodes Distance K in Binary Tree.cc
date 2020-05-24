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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        helper1(target, 0, K, ans);
        helper2(root, target, K, ans);
        return ans;
    }
    void helper1(TreeNode* node, int dist, int k, vector<int>& ans) {
        if (!node) return;
        if (dist == k) {
            ans.push_back(node->val);
            return;
        }
        helper1(node->left, dist + 1, k, ans);
        helper1(node->right, dist + 1, k, ans);
    }
    int helper2(TreeNode* node, TreeNode* target, int k, vector<int>& ans) {
        // return distance from target
        if (!node) return -1;
        if (node == target) return 0;
        
        int left = helper2(node->left, target, k, ans);
        int right = helper2(node->right, target, k, ans);
        
        if (left != -1) {
            if (left + 1 == k) {
                ans.push_back(node->val);
            }
            helper1(node->right, left + 2, k, ans);
            return left + 1;
        }
        if (right != -1) {
            if (right + 1 == k) {
                ans.push_back(node->val);
            }
            helper1(node->left, right + 2, k, ans);
            return right + 1;
        }
        return -1;
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