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
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (try_square(p1, p2, p3, p4) ||
        	try_square(p1, p3, p2, p4) ||
        	try_square(p1, p4, p2, p3)) return true;
        return false;
    }
    bool try_square(vector<int>& p, vector<int>& q, vector<int>& r, vector<int>& s) {
    	if (p[0] == q[0] && p[1] == q[1]) return false;
    	if ((q[0] - p[0])*(q[0] - p[0]) + (q[1] - p[1])*(q[1] - p[1]) == 
    		(r[0] - s[0])*(r[0] - s[0]) + (r[1] - s[1])*(r[1] - s[1]) &&
    		q[0] + p[0] == r[0] + s[0] &&
    		q[1] + p[1] == r[1] + s[1] && 
    		(p[0] - r[0])*(p[0] - r[0]) + (p[1] - r[1])*(p[1] - r[1]) ==
    		(p[0] - s[0])*(p[0] - s[0]) + (p[1] - s[1])*(p[1] - s[1])) return true;
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
	int a1[] = {0,0}, a2[] = {5,0}, a3[] = {0,4}, a4[] = {5,4};
	vector<int> p1(a1, a1 + 2), p2(a2, a2 + 2), p3(a3, a3 + 2), p4(a4, a4 + 2);

	cout << sol.validSquare(p1, p2, p3, p4) << endl;


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