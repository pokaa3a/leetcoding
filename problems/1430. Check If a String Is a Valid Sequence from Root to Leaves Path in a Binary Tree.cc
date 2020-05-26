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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        queue<TreeNode*> q;
        if (root->val != arr[0]) return false;
        q.push(root);
        int idx = 0;

        while (!q.empty()) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; i++) {
        		TreeNode* cur = q.front();
        		q.pop();

        		if (idx == arr.size() - 1 && 
        			!cur->left && !cur->right) return true;

        		if (idx + 1 < arr.size() && cur->left && cur->left->val == arr[idx + 1]) {
        			q.push(cur->left);
        		}
        		if (idx + 1 < arr.size() && cur->right && cur->right->val == arr[idx + 1]) {
        			q.push(cur->right);
        		}
        	}
        	if (++idx == arr.size()) return false;
        }
        return false;
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