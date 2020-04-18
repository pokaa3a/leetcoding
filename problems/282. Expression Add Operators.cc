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

// DFS complexity is 4^N
// stoi / to_string is N
// overall complexity is O(N*4^N)

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(num, "", target, 0, 0, ans);
        return ans;
    }
    void dfs(string num, string cur, long long target, long long sum, long long prev, vector<string>& ans) {
        if (num.size() == 0) {
            if (sum == target) {
                ans.push_back(cur);
            }
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            string s = num.substr(0, i + 1);
            if (s.size() > 1 && s[0] == '0') continue;
            
            int n = stoll(s);
            stringstream ss(s);
            long long n;
            ss >> n;
            
            if (cur.size() == 0) {
                // head
                dfs(num.substr(i + 1), s, target, n, n, ans);
            } else {
                // +
                dfs(num.substr(i + 1), cur + "+" + s, target, sum + n, n, ans);
                // -
                dfs(num.substr(i + 1), cur + "-" + s, target, sum - n, -n, ans);
                // *
                dfs(num.substr(i + 1), cur + "*" + s, target, (sum - prev) + prev * n, prev * n, ans);
            }
        }
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string num = "2147483648";
	int target = -2147483648;

	vector<string> ans = sol.addOperators(num, target);
	for (string x : ans) cout << x << endl;

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