#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
// 	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
// 		set<int> s;
// 		for (int i = 0; i < to_delete.size(); ++i) {
// 			s.insert(to_delete[i]);
// 		}

// 		vector<TreeNode*> res;
// 		if (root->left) {
// 			dfs(root->left, root, true, s, res);
// 		}
// 		if (root->right) {
// 			dfs(root->right, root, false, s, res);
// 		}
// 		if (s.find(root->val) != s.end()) {
// 			if (root->left) res.push_back(root->left);
// 			if (root->right) res.push_back(root->right);
// 		} else {
// 			res.push_back(root);
// 		}
// 		return res;
// 	}
// private:
// 	void dfs(TreeNode* root, TreeNode* prev, bool isLeft, set<int>& s, vector<TreeNode*>& res) {
// 		if (!root) return;

// 		if (root->left) {
// 			dfs(root->left, root, true, s, res);
// 		}
// 		if (root->right) {
// 			dfs(root->right, root, false, s, res);
// 		}
// 		if (s.find(root->val) != s.end()) {
// 			if (root->left) res.push_back(root->left);
// 			if (root->right) res.push_back(root->right);
// 			if (isLeft) prev->left = NULL;
// 			else prev->right = NULL;
// 		}
// 	}
// };

class Solution {
private:
    set<int> del;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i = 0; i < to_delete.size(); ++i) {
            del.insert(to_delete[i]);
        }
        
        vector<TreeNode*> ans;
        dfs(root, ans);
        if (del.count(root->val) == 0) ans.push_back(root);
        return ans;
    }
    void dfs(TreeNode* root, vector<TreeNode*>& ans) {
        if (!root) {
            return;
        }
        dfs(root->left, ans);
        dfs(root->right, ans);
        if (del.count(root->val) == 0) {
        	cout << "root: " << root->val << " keep" << endl;
            if (root->left && del.count(root->left->val) > 0) {
                root->left = NULL;
            }
            if (root->right && del.count(root->right->val) > 0) {
                root->right = NULL;
            }
        } else {
        	cout << "root: " << root->val << " delete" << endl;
            if (root->left && del.count(root->left->val) == 0) {
            	cout << "add: " << root->left->val << endl;
                ans.push_back(root->left);
            }
            if (root->right && del.count(root->right->val) == 0) {
            	cout << "add: " << root->right->val << endl;
                ans.push_back(root->right);
            }
        }
    }
};

void dfs(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	if (root->left) dfs(root->left);
	if (root->right) dfs(root->right);
}

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	int del_array[] = {3, 5};
	vector<int> to_delete(del_array, del_array + 2);

	Solution sol;
	vector<TreeNode*> res = sol.delNodes(n1, to_delete);
	for (int i = 0; i < res.size(); ++i) {
		dfs(res[i]);
		cout << endl;
	}
}