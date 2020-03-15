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
    bool reachingPoints(int sx, int sy, int tx, int ty) {

    	while (tx >= sx && ty >= sy) {
    		if (tx == sx && ty == sy) return true;

    		if (tx > ty) {
    			if (ty > sy) tx %= ty;
    			else return (tx - sx) % sy == 0;
    		} else if (ty > tx) {
    			if (tx > sx) ty %= tx;
    			else return (ty - sy) % sx == 0;
    		} else break;
    	}
    	return sx == tx && sy == ty;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int sx = 10, sy = 1, tx = 17, ty = 17;
	cout << sol.reachingPoints(sx, sy, tx, ty) << endl;

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