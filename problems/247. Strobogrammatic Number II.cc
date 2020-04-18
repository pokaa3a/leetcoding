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
    vector<string> findStrobogrammatic(int n) {
        vector<string> output;
        vector<string> cand = helper(n);
        for (string s : cand) {
            if (s.size() > 1 && s[0] == '0') continue;
            output.push_back(s);
        }
        return output;
    }
    vector<string> helper(int n) {
        if (n == 0) return vector<string>({""});
        if (n == 1) return vector<string>({"0", "1", "8"});
        
        vector<string> output;
        vector<string> next = helper(n - 2);
        for (string s : next) {
            output.push_back("0" + s + "0");
            output.push_back("1" + s + "1");
            output.push_back("6" + s + "9");
            output.push_back("8" + s + "8");
            output.push_back("9" + s + "6");
        }
        return output;
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