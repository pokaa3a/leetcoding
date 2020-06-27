#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <list>
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
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> folders;
        int n = names.size();
        vector<string> res;
        
        string s;
        for (auto name : names) {
            s = name;
            while (folders.count(s) > 0) {
                folders[name]++;
                s = name + "(" + to_string(folders[name]) + ")";
            }
            res.push_back(s);
            folders[s] = 0;
        }
        return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> names = {"kaido","kaido(1)","kaido","kaido(1)"};
	vector<string> res = sol.getFolderNames(names);

	for (auto x : res) cout << x << endl;
}