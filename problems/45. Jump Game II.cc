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
    int jump(vector<int>& nums) {
    	int n = nums.size();
    	if (n <= 1) return 0;

    	int max_pos = nums[0], max_reach = nums[0], steps = 1;
    	for (int i = 1; i < n; i++) {
    		if (max_reach < i) {
    			steps++;
    			max_reach = max_pos;
    		}
    		max_pos = max(max_pos, i + nums[i]);
    	}
    	return steps;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {2,3,1,1,4};
	vector<int> nums(a, a + sizeof(a) / sizeof(int));

	cout << sol.jump(nums) << endl;

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