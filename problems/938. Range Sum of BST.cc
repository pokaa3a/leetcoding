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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;

        if (root->val > R) {
        	return rangeSumBST(root->left, L, R);
        } else if (root->val < L) {
        	return rangeSumBST(root->right, L, R);
        }
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	TreeNode* n1 = new TreeNode(10);
	TreeNode* n2 = new TreeNode(5);
	TreeNode* n3 = new TreeNode(15);
	TreeNode* n4 = new TreeNode(3);
	TreeNode* n5 = new TreeNode(7);
	TreeNode* n6 = new TreeNode(18);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->right = n6;
	int L = 7, R = 15;
	cout << sol.rangeSumBST(n1, L, R) << endl;

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