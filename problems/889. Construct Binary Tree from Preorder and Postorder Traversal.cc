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

void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << endl;
	inorder(root->right);
}
void preorder(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	preorder(root->left);
	preorder(root->right);
}
void postorder(TreeNode* root) {
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << endl;
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
       return construct(0, pre.size() - 1, 0, post.size() - 1, pre, post);
    }
    TreeNode* construct(int pre_lo, int pre_hi, int pos_lo, int pos_hi, vector<int>& pre, vector<int>& post) {
    	if (pre_lo > pre_hi) return NULL;
    	if (pre_lo - pre_hi == 0) {
    		TreeNode* root = new TreeNode(pre[pre_lo]);
    		return root;
    	}
    	TreeNode* root = new TreeNode(pre[pre_lo]);
    	int left_root = pre[pre_lo + 1], right_root = post[pos_hi - 1];
    	if (left_root == right_root) {
    		root->left = construct(pre_lo + 1, pre_hi, pos_lo, pos_hi - 1, pre, post);
    	} else {
    		int i = pre_lo + 1;
    		while (pre[i] != right_root) {
    			i++;
    		}
    		// pre[i] == right_root
    		// cout << "root: " << root->val << endl;
    		int left_size = (i - 1) - (pre_lo + 1) + 1, right_size = pre_hi - i + 1;
    		// cout << "LEFT:" << endl;
    		// cout << "  pre " << pre[pre_lo + 1] << " to " << pre[pre_lo + left_size] << endl;
    		// cout << "  pos " << post[pos_lo] << " to " << post[pos_lo + left_size - 1] << endl;
    		// cout << "RIGHT:" << endl;
    		// cout << "  pre " << pre[i] << " to " << pre[pre_hi] << endl;
    		// cout << "  pos " << post[pos_hi - right_size] << " to " << post[pos_hi - 1] << endl;
    		root->left = construct(pre_lo + 1, pre_lo + left_size, pos_lo, pos_lo + left_size - 1, pre, post);
    		root->right = construct(i, pre_hi, pos_hi - right_size, pos_hi - 1, pre, post);
    	}
    	return root;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> pre = {1,2,4,5,3,6,7}, post = {4,5,2,6,7,3,1};
	TreeNode* root = sol.constructFromPrePost(pre, post);
	postorder(root);

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