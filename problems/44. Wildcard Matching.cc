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
// O(sp)
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() || p.empty()) return false;
        if (p == "*") return true;

        int s_len = s.size(), p_len = p.size();
        vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= p_len; j++) {
        	if (p[j - 1] == '*') {
        		int i = 0;
        		while (i <= s_len && !dp[i][j - 1]) i++;
        		// dp[i][j - 1] = true
        		for (; i <= s_len; i++) dp[i][j] = true;
        	} else if (p[j - 1] == '?') {
        		for (int i = 1; i <= s_len; i++) {
        			dp[i][j] = dp[i - 1][j - 1];
        		}
        	} else {
        		for (int i = 1; i <= s_len; i++) {
        			dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
        		}
        	}
        }
        return dp[s_len][p_len];
    }
};

// O(min(s, p))
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size(), p_len = p.size();
        int s_idx = 0, p_idx = 0;
        int star_idx = -1, s_tmp_idx = -1;
        
        while (s_idx < s_len) {
            if (p_idx < p_len && (p[p_idx] == s[s_idx] || p[p_idx] == '?')) {
                p_idx++;
                s_idx++;
            } else if (p_idx < p_len && p[p_idx] == '*') {
                star_idx = p_idx;
                s_tmp_idx = s_idx;
                p_idx++;
            } else {
                if (star_idx == -1) return false;
                p_idx = star_idx + 1;
                s_idx = s_tmp_idx + 1;
                s_tmp_idx = s_idx;
            }
        }
        for (; p_idx < p_len; p_idx++) {
            if (p[p_idx] != '*') return false;
        }
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "a", p = "?*";
	cout << sol.isMatch(s, p) << endl;

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