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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;

        int max_len = parse(s, words);
        vector<string> ans(max_len, string(words.size(), ' '));

        for (int i = 0; i < words.size(); ++i) {
        	for (int j = 0; j < words[i].size(); ++j) {
        		ans[j][i] = words[i][j];
        	}
        }

        for (int i = 0; i < ans.size(); ++i) {
        	string a = ans[i];
        	reverse(a.begin(), a.end());
        	a = a.substr(a.find_first_not_of(' '));
        	reverse(a.begin(), a.end());
        	ans[i] = a;
        }

        return ans;
    }

    int parse(string s, vector<string>& words) {
    	stringstream ss(s);
    	string token;
    	int max_len = 0;
    	while (getline(ss, token, ' ')) {
    		words.push_back(token);
    		max_len = max(max_len, (int)token.size());
    	}
    	return max_len;
    }
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

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