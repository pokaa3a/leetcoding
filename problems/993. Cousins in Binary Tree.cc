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
    bool isCousins(TreeNode* root, int x, int y) {
    	if (x == y) return false;
        if (root->val == x || root->val == y) return false;

        int cur_depth = 0;
        int first_parent = -1, first_depth = -1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	int q_size = q.size();
        	cur_depth++;
        	for (int i = 0; i < q_size; ++i) {
        		TreeNode* n = q.front(); q.pop();

        		if (n->left) {
        			if (n->left->val == x || n->left->val == y) {
        				if (first_parent == -1) {
        					first_parent = n->val;
        					first_depth = cur_depth;
        				} else {
        					if (first_parent != n->val && first_depth == cur_depth) return true;
        					else return false;
        				}
        			}
        			q.push(n->left);
        		}
        		if (n->right) {
        			if (n->right->val == x || n->right->val == y) {
        				if (first_parent == -1) {
        					first_parent = n->val;
        					first_depth = cur_depth; 
        				} else {
        					if (first_parent != n->val && first_depth == cur_depth) return true;
        					else return false;
        				}
        			}
        			q.push(n->right);
        		}
        	}
        }
        return false;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	n1->left = n2;
	n1->right = n3;
	n2->right = n4;
	n3->right = n5;
	cout << sol.isCousins(n1, 5, 4) << endl;

}