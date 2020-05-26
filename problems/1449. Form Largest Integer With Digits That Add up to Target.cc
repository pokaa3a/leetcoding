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
    string largestNumber(vector<int>& cost, int target) {
         unordered_map<int, string> memo;
         return dp(target, cost, memo);
    }
    string dp(int target, vector<int>& cost, unordered_map<int, string>& memo) {
    	if (target < 0) return "0";
    	else if (target == 0) return "";
    	else if (memo.count(target)) return memo[target];

    	string res = "0";
    	for (int d = 1; d <= 9; d++) {
    		string cur = dp(target - cost[d - 1], cost, memo);
    		if (cur == "0") continue;
    		cur = to_string(d) + cur;
    		if (cur.size() >= res.size()) res = cur;
    	}
    	memo[target] = res;
    	return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> cost = {4,3,2,5,6,7,2,5,5};
	int target = 9;
	cout << sol.largestNumber(cost, target) << endl;

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