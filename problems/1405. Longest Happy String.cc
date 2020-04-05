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
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> v;
        if (a) v.push_back(make_pair(a, 'a'));
        if (b) v.push_back(make_pair(b, 'b'));
        if (c) v.push_back(make_pair(c, 'c'));

        string ans = "";
        while (v.size()) {
        	sort(v.begin(), v.end(), greater<pair<int, char>>());
        	for (int i = 0; i < v.size(); i++) {
        		if (can_add(ans, v, i)) {
        			ans += string(1, v[i].second);
        			if (--v[i].first == 0) {
        				v.erase(v.begin() + i);
        			}
        			break;
        		}
        	}
        	if (v.size() == 1 && !can_add(ans, v, 0)) break;
        }
        return ans;
    }
    bool can_add(string s, vector<pair<int, char>>& v, int i) {
    	if (s.size() < 2) return true;
    	if (v[i].first == 0) return false;
    	if (s[s.size() - 1] == s[s.size() - 2] && s[s.size() - 1] == v[i].second) return false;
    	return true;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a = 7, b = 1, c = 0;
	cout << sol.longestDiverseString(a, b, c) << endl;

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