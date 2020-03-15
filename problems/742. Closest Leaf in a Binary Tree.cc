#include <iostream>
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
	int findClosestLeaf(TreeNode* root, int k) {
		queue<TreeNode*> q;
		set<TreeNode*> visited;
		TreeNode* node_k = dfs(root, k);
		q.push(node_k);
		visited.insert(node_k);

		while (!q.empty()) {
			int q_size = q.size();
			for (int i = 0; i < q_size; ++i) {
				TreeNode* cur = q.front();
				q.pop();
				if (!cur->left && !cur->right) return cur->val;
				if (cur->left && visited.find(cur->left) == visited.end()) {
					q.push(cur->left);
					visited.insert(cur->left);
				}
				if (cur->right && visited.find(cur->right) == visited.end()) {
					q.push(cur->right);
					visited.insert(cur->right);
				}
				if (backMap.find(cur) != backMap.end() && 
					visited.find(backMap[cur]) == visited.end()) {
					q.push(backMap[cur]);
					visited.insert(backMap[cur]);
				}
			}
		}
		return -1;
	}
private:
	map<TreeNode*, TreeNode*> backMap;
	TreeNode* dfs(TreeNode* root, int k) {
		if (!root) return NULL;
		if (root->val == k) return root;
		if (root->left) {
			backMap[root->left] = root;
			TreeNode* left = dfs(root->left, k);
			if (left) return left;
		}
		if (root->right) {
			backMap[root->right] = root;
			TreeNode* right = dfs(root->right, k);
			if (right) return right;
		}
		return NULL;
	}
};

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	// TreeNode* n4 = new TreeNode(4);
	// TreeNode* n5 = new TreeNode(5);
	// TreeNode* n6 = new TreeNode(6);
	// TreeNode* n7 = new TreeNode(7);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n5->left = n6;
	n5->right = n7;
	int k = 4;
	Solution sol;
	cout << sol.findClosestLeaf(n1, k) << endl;
}