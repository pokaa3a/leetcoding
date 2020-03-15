#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > findLeaves(TreeNode* root) {
		if (!root) return vector<vector<int> >();
		vector<vector<int> > ans;
		ans.push_back(vector<int>());
		while (getLeaves(root, ans.back())) {
			ans.push_back(vector<int>());
		}
		return ans;
	}
private:
	bool getLeaves(TreeNode* root, vector<int>& output) {
		if (!root) return false;
		if (isLeaf(root)) {
			output.push_back(root->val);
			return false;
		}
		if (root->left) {
			if (isLeaf(root->left)) {
				output.push_back(root->left->val);
				root->left = NULL;
			} else {
				getLeaves(root->left, output);
			}
		}
		if (root->right) {
			if (isLeaf(root->right)) {
				output.push_back(root->right->val);
				root->right = NULL;
			} else {
				getLeaves(root->right, output);
			}
		}
		return true;
	}

	bool isLeaf(TreeNode* root) {
		if (!root) return false;
		if (!root->left && !root->right) {
			return true;
		}
		return false;
	}
};

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

	Solution sol;
	vector<vector<int> > ans = sol.findLeaves(n1);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}