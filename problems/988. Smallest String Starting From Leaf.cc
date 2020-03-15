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
using namespace std;

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
private:
	set<string> ss;
public:
    string smallestFromLeaf(TreeNode* root) {
        string root_s = "";
        helper(root, root_s);
        return *ss.begin();
    }
    void helper(TreeNode* root, string s) {
    	s += char(root->val + 'a');
    	if (!root->left && !root->right) {
    		reverse(s.begin(), s.end());
    		ss.insert(s);
    	}
    	if (root->left) helper(root->left, s);
    	if (root->right) helper(root->right, s);
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	TreeNode* n1 = new TreeNode(4);
	TreeNode* n2 = new TreeNode(0);
	TreeNode* n3 = new TreeNode(1);
	TreeNode* n4 = new TreeNode(1);
	// TreeNode* n5 = new TreeNode(0);
	// TreeNode* n6 = new TreeNode(0);
	// TreeNode* n7 = new TreeNode(4);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	// n2->right = n4;
	// n3->left = n5;
	// n4->left = n6;

	cout << sol.smallestFromLeaf(n1) << endl;
}