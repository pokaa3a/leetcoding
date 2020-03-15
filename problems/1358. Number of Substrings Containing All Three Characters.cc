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
    int numberOfSubstrings(string s) {
        unordered_map<char, int> cnt;
        int left = 0, right = 0, ans = 0;

        cnt[s[right]]++;
        while (left < s.size() && right < s.size()) {
        	while (cnt['a'] < 1 || cnt['b'] < 1 || cnt['c'] < 1) {
        		right++;
        		if (right == s.size()) break;
        		cnt[s[right]]++;
        	}
        	if (right == s.size()) break;
        	// cout << s.substr(left, right - left + 1) << endl;
        	ans += s.size() - right;

        	cnt[s[left]]--;
        	left++;
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "abcabc";

	cout << sol.numberOfSubstrings(s) << endl;

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

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