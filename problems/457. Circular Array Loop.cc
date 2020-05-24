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
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> status(n, 0);	// 0: not visied, 1: visited, 2: done visited
        bool res = false;

        for (int i = 0; i < n; i++) {
        	if (status[i] == 0) dfs(i, nums[i] > 0, nums, status, res);
        	if (res) return true;
        }
        return false;
    }
    void dfs(int i, bool forward, vector<int>& nums, vector<int>& status, bool& res) {
    	if ((forward && nums[i] < 0) || (!forward && nums[i] > 0)) return;
    	if (status[i] == 1) {
    		res = true;
    		return;
    	} else if (status[i] == 2) return;

    	status[i] = 1;
    	int n = nums.size();
    	int next = (i + nums[i]) % n;
    	next = next < 0 ? next + n : next;
    	if (next != i) dfs(next, forward, nums, status, res);
    	status[i] = 2;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> nums = {2,-1,1,2,2};
	cout << sol.circularArrayLoop(nums) << endl;

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