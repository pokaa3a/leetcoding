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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, 
    							 vector<int>& rightChild) {
    	vector<int> parents(n, 0);
    	vector<int> children(n, 0);

    	for (int i = 0; i < leftChild.size(); ++i) {
    		int left = leftChild[i], right = rightChild[i];
    		if (left >= 0) {
    			if (++parents[left] > 1) return false;
    			if (++children[i] > 2) return false;
    		}
    		if (right >= 0) {
    			if (++parents[right] > 1) return false;
    			if (++children[i] > 2) return false;
    		}
    	}
        return accumulate(parents.begin(), parents.end(), 0) == (n - 1);
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n = 6;
	int left[] = {1,-1,-1,4,-1,-1}, right[] = {2,-1,-1,5,-1,-1};
	vector<int> leftChild(left, left + n), rightChild(right, right + n);

	cout << sol.validateBinaryTreeNodes(n, leftChild, rightChild) << endl;

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