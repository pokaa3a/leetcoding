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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        if (nums.size() == 1) {
        	ans.push_back(to_string(nums[0]));
        	return ans;
        }

        int start = nums[0];
        for (int i = 1; i < nums.size(); i++) {
        	if (nums[i]> 1 + nums[i - 1]) {
        		if (start == nums[i - 1]) ans.push_back(to_string(start));
        		else {
	        		string s = to_string(start) + "->" + to_string(nums[i - 1]);
	        		ans.push_back(s);
        		}
        		start = nums[i];
        	}
        }
        if (start == nums.back()) ans.push_back(to_string(start));
        else {
	        string s = to_string(start) + "->" + to_string(nums.back());
	        ans.push_back(s);
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