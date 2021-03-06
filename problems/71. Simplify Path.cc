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
    string simplifyPath(string path) {
        stack<string> stk;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/') {
                int j = i;
                while (j + 1 < path.size() && path[j + 1] != '/') {
                    j++;
                }
                string token = path.substr(i, j - i + 1);
                i = j;
                if (token == ".") {
                    continue;
                } else if (token == "..") {
                    if (!stk.empty()) stk.pop();
                } else {
                    stk.push(token);
                }
            }
        }
        string output = "";
        while (!stk.empty()) {
            output = "/" + stk.top() + output;
            stk.pop();
        }
        return output == "" ? "/" : output;
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