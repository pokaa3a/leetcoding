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
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<pair<int, int> > > dict(26, vector<pair<int, int> >());
        for (int i = 0; i < words.size(); i++) {
        	dict[words[i][0] - 'a'].push_back(make_pair(i, 0));
        }
        int ans = 0;

        for (int i = 0; i < S.size(); i++) {
        	char c = S[i];
        	vector<pair<int, int> > bucket = dict[c - 'a'];
        	dict[c - 'a'] = vector<pair<int, int> >();
        	for (int j = 0; j < bucket.size(); j++) {
        		pair<int, int> p = bucket[j];
        		if (p.second == words[p.first].size() - 1) ans++;
        		else dict[words[p.first][p.second + 1] - 'a'].push_back(make_pair(p.first, p.second + 1));
        	}
        }
    	return ans;
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