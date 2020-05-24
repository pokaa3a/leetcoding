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

// Alternative solution: BFS
// => at each level, check if the above tree is complete

const int MOD = 1000000007;
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int height, n_nodes;
        return is_complete(root, height, n_nodes);
    }
    bool is_complete(TreeNode* root, int& height, int& n_nodes) {
    	if (!root) {
    		height = 0;
    		n_nodes = 0;
    		return true;
    	}

    	int height_l, n_nodes_l, height_r, n_nodes_r;

    	bool left = is_complete(root->left, height_l, n_nodes_l);
    	bool right = is_complete(root->right, height_r, n_nodes_r);

    	cout << "Node: " << root->val << endl;
    	cout << "height_l = " << height_l << ", n_nodes_l = " << n_nodes_l << endl;
    	cout << "height_r = " << height_r << ", n_nodes_r = " << n_nodes_r << endl;

    	if (!left || !right) return false;
    	if (n_nodes_r > n_nodes_l) return false;

    	if (n_nodes_l == 0) {
    		height = 1;
    		n_nodes = 1;
    		return true;
    	} else if (n_nodes_r == 0) {
    		if (n_nodes_l > 1) return false;
    		height = height_l + 1;
    		n_nodes = n_nodes_l + 1;
    		return true;
    	}

    	if (height_l == height_r) {
    		if (n_nodes_l != (1 << height_l) - 1) return false;
    		if (!(n_nodes_r >= (1 << (height_r - 1)) && (n_nodes_r < (1 << height_l)))) return false;
    	} else if (height_l == (height_r + 1)) {
    		if (!(n_nodes_l >= (1 << (height_l - 1)) && (n_nodes_l < (1 << height_l)))) return false;
    		if (n_nodes_r != (1 << height_r) - 1) return false;
    	} else {
    		return false;
    	}
    	height = max(height_l, height_r) + 1;
    	n_nodes = n_nodes_l + n_nodes_r + 1;
    	return true;
    }
};

// BFS
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        
        bool findEnd = false;
        
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                
                if (findEnd && (cur->left || cur->right)) return false;
                if (!cur->left && cur->right) return false;
                if (!cur->right) findEnd = true;
                
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);

	n1->left = n2;
	n2->left = n3;
	n2->right = n4;

	cout << sol.isCompleteTree(n1) << endl;

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