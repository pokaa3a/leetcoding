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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> b_union(26, 0);
        for (int i = 0; i < B.size(); i++) {
        	vector<int> count(26, 0);
        	for (int j = 0; j < B[i].size(); j++) {
        		count[B[i][j] - 'a']++;
        		b_union[B[i][j] - 'a'] = max(b_union[B[i][j] - 'a'], count[B[i][j] - 'a']);
        	}
        }

        vector<string> ans;
        for (int i = 0; i < A.size(); i++) {
        	vector<int> count(26, 0);
        	for (int j = 0; j < A[i].size(); j++) {
        		count[A[i][j] - 'a']++;
        	}
        	bool valid = true;
        	for (int k = 0; k < 26; k++) {
        		if (count[k] < b_union[k]) {
        			valid = false;
        			break;
        		}
        	}
        	if (valid) ans.push_back(A[i]);
        }
        return ans;
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