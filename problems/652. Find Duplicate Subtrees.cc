#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	unordered_map<string, int> um;
	vector<TreeNode*> node_list;
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return node_list;
	}
	string dfs(TreeNode* root) {
		if (!root) return "#";

		string hash = to_string(root->val);
		hash += "L" + dfs(root->left);
		hash += "R" + dfs(root->right);

		if (um.find(hash) != um.end() && um[hash] == 1) {
			node_list.push_back(root);
		}
		um[hash]++;
		return hash;
	}
};

int main() {
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(2);
	TreeNode *n6 = new TreeNode(4);
	TreeNode *n7 = new TreeNode(4);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	n5->left = n7;

	Solution sol;
	vector<TreeNode*> list = sol.findDuplicateSubtrees(n1);

	for (int i = 0; i < list.size(); ++i) {
		cout << list[i]->val << " ";
	}
}