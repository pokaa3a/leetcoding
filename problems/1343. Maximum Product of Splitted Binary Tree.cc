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
const long long MOD = 1000000007;
class Solution {
public:
    int maxProduct(TreeNode* root) {
    	long long ans = 1;
    	int total = sum_nodes(root);

    	myfunc(root, total, ans);
    	return (int)(ans % MOD);
    }
    
    int sum_nodes(TreeNode* root) {
    	if (!root) return 0;
    	int s = root->val + sum_nodes(root->left) + sum_nodes(root->right);
    	root->val = s;
    	return s;
    }
    void myfunc(TreeNode* root, int& total, long long& ans) {
    	if (!root) return;

    	if (root->left) {
    		int sub = total - root->left->val;
    		ans = max(ans, (long long)sub * (long long)(total - sub));
    		myfunc(root->left, total, ans);
    	}
    	if (root->right) {
    		int sub = total - root->right->val;
    		ans = max(ans, (long long)sub * (long long)(total - sub));
    		myfunc(root->right, total, ans);
    	}
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);

	n1->right = n2;
	n2->left = n3;
	n2->right = n4;
	n4->left = n5;
	n4->right = n6;

	cout << sol.maxProduct(n1) << endl;

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