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
	unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int N) {
        if (memo.count(N) == 0) {
        	vector<TreeNode*> res;
        	if (N == 1) {
        		TreeNode* root = new TreeNode(0);
        		res.push_back(root);
        	} else if (N % 2 == 1) {
        		for (int x = 0; x < N; x++) {
        			int y = N - 1 - x;
        			for (TreeNode* left : allPossibleFBT(x)) {
        				for (TreeNode* right : allPossibleFBT(y)) {
        					TreeNode* root = new TreeNode(0);
        					root->left = copy(left);
        					root->right = copy(right);
        					res.push_back(root);
        				}
        			}
        		}
        	}
        	memo[N] = res;
        }
        return memo[N];
    }
    TreeNode* copy(TreeNode* root) {
    	if (!root) return nullptr;
    	TreeNode* new_root = new TreeNode(0);
    	new_root->left = copy(root->left);
    	new_root->right = copy(root->right);
    	return new_root;
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