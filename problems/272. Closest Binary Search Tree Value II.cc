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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
    	vector<int> res;
    	queue<int> q;
    	dfs(root, q, target, k);

    	while (!q.empty()) {
    		res.push_back(q.front());
   			q.pop();
    	}
    	return res;
    }
    void dfs(TreeNode* node, queue<int>& q, double target, int k) {
    	if (!node) return;
    	dfs(node->left, q, target, k);

    	if (q.size() < k) {
    		q.push(node->val);
    	} else {
    		if (abs(q.front() - target) > abs(node->val - target)) {
    			q.pop();
    			q.push(node->val);
    		} else {
    			return;
    		}
    	}
    	dfs(node->right, q, target, k);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(1);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(3);
	n1->left = n2;
	n2->left = n3;
	n2->right = n4;
	n4->left = n5;

	int k = 2;
	double target = 3.4;
	vector<int> res = sol.closestKValues(n1, target, k);
	for (int x : res) cout << x << " ";
	cout << endl;

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