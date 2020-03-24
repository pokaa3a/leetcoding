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
	bool is_palindrome(unsigned long long num) {
		string s = to_string(num);
		int n = s.size();
		string ss, ss_r;
		if (n % 2 == 0) {
			ss = s.substr(0, n / 2);
			ss_r = s.substr(n / 2);
			reverse(ss_r.begin(), ss_r.end());
		} else {
			ss = s.substr(0, n / 2);
			ss_r = s.substr(n / 2 + 1);
			reverse(ss_r.begin(), ss_r.end());
		}
		return ss == ss_r;
	}

    int superpalindromesInRange(string L, string R) {
        // let P = R^2 < 1e19
        // so R <= 1e9.5
        // s|s' = string(R), so int(s) = k <= 1e5

    	const int MAGIC = 100000;
    	int ans = 0;
        for (int k = 1; k <= MAGIC; ++k) {
        	string s = to_string(k);

        	// odd: '1234' -> '1234321'
        	string s_r = s;
        	reverse(s_r.begin(), s_r.end());
        	string t = s + s_r.substr(1);
        	unsigned long long v = stoull(t) * stoull(t);

        	if (v > stoull(R)) break;
        	if (v >= stoull(L) && is_palindrome(v)) ans++;
        }
        for (int k = 1; k <= MAGIC; ++k) {
        	string s = to_string(k);

        	// even: '1234' -> '12344321'
        	string s_r = s;
        	reverse(s_r.begin(), s_r.end());
        	string t = s + s_r;
        	unsigned long long v = stoull(t) * stoull(t);

        	if (v > stoull(R)) break;
        	if (v >= stoull(L) && is_palindrome(v)) ans++;
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string L = "4", R = "1000";
	cout << sol.superpalindromesInRange(L, R) << endl;

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