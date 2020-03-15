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
	vector<string> ans;
	unordered_set<string> seen;
	int min_rm;
public:
    vector<string> removeInvalidParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
        	if (s[i] == '(') st.push(0);
        	else if (s[i] == ')') {
        		if (st.empty() || st.top() == 1) st.push(1);
        		else st.pop();
        	}
        }
        min_rm = st.size();
        dfs(0, 0, "", s);
        return ans;
    }

    void dfs(int i, int left, string cand, string& s) {
    	if (i == s.size()) {
    		if (left == 0 && seen.count(cand) == 0) {
    			ans.push_back(cand);
    			seen.insert(cand);
    		}
    		return;
    	}

    	if (s[i] == '(') {
    		// not add this
    		if (i + 1 - cand.size() <= min_rm) dfs(i + 1, left, cand, s);

    		// add this
    		cand += '(';
    		left++;
    		dfs(i + 1, left, cand, s);

    	} else if (s[i] == ')') {
    		// not add this
    		if (i + 1 - cand.size() <= min_rm) dfs(i + 1, left, cand, s);

    		// add this
    		if (left > 0) {
    			cand += ')';
    			left--;
    			dfs(i + 1, left, cand, s);
    		}
    	} else {
    		cand += s[i];
    		dfs(i + 1, left, cand, s);
    	}
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = ")(";
	vector<string> ans = sol.removeInvalidParentheses(s);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

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