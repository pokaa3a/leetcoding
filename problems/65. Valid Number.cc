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
    bool isNumber(string s) {
        
        // clear leading spaces
        while (s.size() > 0 && s[0] == ' ') s = s.substr(1);
        // clear ending spaces
        while (s.size() > 0 && s.back() == ' ') s = s.substr(0, s.size() - 1);

        if (s.size() == 0) return false;
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);

        bool has_exponent = false;
        bool has_decimal_point = false;

        for (int i = 0; i < s.size(); i++) {
        	char c = s[i];
        	if (c == 'e') {
        		if (has_exponent || i == 0) return false;
        		if (s[i + 1] == '+' || s[i + 1] == '-') i++;
        		if (i == s.size() - 1) return false;
        		has_exponent = true;
        	} else if (c == '.') {
        		if (has_exponent || has_decimal_point) return false;
        		if (i == 0 && i == s.size() - 1) return false;	// "."
        		if (i == 0 && s[i + 1] == 'e') return false;
        		has_decimal_point = true;
        	} else if (!isdigit(c)) {
        		return false;
        	}
        }
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "1e.";
	cout << sol.isNumber(s) << endl;

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