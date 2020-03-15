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
    string sortString(string s) {
        vector<int> count(26, 0);
        for (int i = 0; i < s.size(); ++i) {
        	count[s[i] - 'a']++;
        }

        string ans = "";
        while (ans.size() < s.size()) {
        	for (int i = 0; i < 26; i++) {
        		if (count[i] > 0) {
        			count[i]--;
        			ans += char(i + 'a');
        		}
        	}
        	for (int i = 25; i >= 0; i--) {
        		if (count[i] > 0) {
        			count[i]--;
        			ans += char(i + 'a');
        		}
        	}
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "gggggg";
	cout << sol.sortString(s) << endl;

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