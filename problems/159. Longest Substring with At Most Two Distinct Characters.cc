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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 2) return s.size();

        char c1, c2 = s[0];
        int start = 0, c2_start = 0, ans = 0;
        for (int i = 1; i < s.size(); i++) {
        	char c = s[i];
        	if (c == c1) {
        		swap(c1, c2);
        		c2_start = i;
        	} else if (c == c2) {
        		// no need to change
        	} else {
        		c1 = c2;
        		c2 = s[i];
        		start = c2_start;
        		c2_start = i;
        	}
        	ans = max(ans, i - start + 1);
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "ccaabbb";
	cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;

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