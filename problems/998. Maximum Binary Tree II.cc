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
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
   		TreeNode* new_node = new TreeNode(val);
   		if (!root) {
   			return new_node;
   		}

   		if (val > root->val) {
   			new_node->left = root;
   			return new_node;
   		} else {
   			root->right = insertIntoMaxTree(root->right, val);
   		}
   		return root;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}