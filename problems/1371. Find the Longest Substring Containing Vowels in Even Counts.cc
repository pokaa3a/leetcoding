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
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;
        int ans = 0, vowel = 0;
        m[0] = 0;
        for (int i = 0; i < s.size(); ++i) {
        	if (s[i] == 'a') {
        		vowel ^= (1 << 0);
        	} else if (s[i] == 'e') {
        		vowel ^= (1 << 1);
        	} else if (s[i] == 'i') {
        		vowel ^= (1 << 2);
        	} else if (s[i] == 'o') {
        		vowel ^= (1 << 3);
        	} else if (s[i] == 'u') {
        		vowel ^= (1 << 4);
        	}
        	if (m.find(vowel) == m.end()) m[vowel] = i + 1;
        	ans = max(ans, i - m[vowel] + 1);
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "bcbcbc";
	cout << sol.findTheLongestSubstring(s) << endl;

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