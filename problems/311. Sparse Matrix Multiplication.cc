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
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    	vector<pair<int, int>> Aij;
    	for (int i = 0; i < A.size(); i++) {
    		for (int j = 0; j < A[0].size(); j++) {
    			if (A[i][j]) Aij.push_back(make_pair(i, j));
    		}
    	}
    	vector<vector<int>> Bij(B.size());
    	for (int i = 0; i < B.size(); i++) {
    		for (int j = 0; j < B[0].size(); j++) {
    			if (B[i][j]) Bij[i].push_back(j);
    		}
    	}

    	vector<vector<int>> output(A.size(), vector<int>(B[0].size(), 0));
    	for (auto p : Aij) {
    		int r = Aij.first, c = Aij.second;
    		for (int k : Bij[c]) {
    			output[r][k] += A[r][c] * B[c][k];
    		}
    	}
    	return output;
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