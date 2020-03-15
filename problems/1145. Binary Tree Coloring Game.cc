#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		dfs(root, x);
		int x_up = n - x_left - x_right - 1;

		if (x_up > x_left + x_right || x_left > x_up + x_right || x_right > x_up + x_left) {
			return true;
		}
		return false;
	}
private:
	int x_left;
	int x_right;
	int dfs(TreeNode* root, int x) {
		if (!root) return 0;
		int left = 0, right = 0;
		if (root->val == x) {
			x_left = dfs(root->left, x);
			x_right = dfs(root->right, x);
			left = x_left;
			right = x_right;
		} else {
			left = dfs(root->left, x);
			right = dfs(root->right, x);
		}
		return left + right + 1;
	}
};

class Solution {
private:
    int left;
    int right;
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        traverse(root, x);
        int top = n - (left + right + 1);
        if (top > left + right ||
            left > top + right ||
            right > top + left) return true;
        return false;
    }
    void traverse(TreeNode* root, int x) {
        if (!root) return;
        if (root->val == x) {
            left = count(root->left);
            right = count(root->right);
        } else {
            traverse(root->left, x);
            traverse(root->right, x);
        }
    }
    int count(TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);	
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	TreeNode* n9 = new TreeNode(9);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->left = n8;
	n4->right = n9;

	int n = 9;
	int x = 3;

	Solution sol;
	cout << sol.btreeGameWinningMove(n1, n, x) << endl;
}