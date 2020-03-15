#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > verticalOrder(TreeNode* root) {
		vector<vector<int> > ans;
		if (!root) return ans;

		unordered_map<int, vector<int> > hash;
		queue<pair<TreeNode*, int> > q;

		int min_col = 0, max_col = 0;

		q.push(make_pair(root, 0));
		while (!q.empty()) {
			int q_size = q.size();
			for (int i = 0; i < q_size; ++i) {
				pair<TreeNode*, int> p = q.front();
				q.pop();
				int col = p.second;
				if (hash.find(col) == hash.end()) {
					hash[col] = vector<int>(1, p.first->val);
				} else {
					hash[col].push_back(p.first->val);
				}

				if (p.first->left) {
					q.push(make_pair(p.first->left, col - 1));
					min_col = min(col - 1, min_col);
				}
				if (p.first->right) {
					q.push(make_pair(p.first->right, col + 1));
					max_col = max(col + 1, max_col);
				}
			}
		}

		for (int i = min_col; i <= max_col; ++i) {
			ans.push_back(hash[i]);
		}
		return ans;
	}
};

int main() {
	/*
	// test case 1
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n9 = new TreeNode(9);
	TreeNode *n8 = new TreeNode(8);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n0 = new TreeNode(0);
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n7 = new TreeNode(7);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n2 = new TreeNode(2);
	n3->left = n9;
	n3->right = n8;
	n9->left = n4;
	n9->right = n0;
	n8->left = n1;
	n8->right = n7;
	n0->left = n5;
	n0->right = n2;
	*/

	// test case 2
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n6 = new TreeNode(6);

	n1->left = n2;
	n1->right = n3;
	n2->right = n5;
	n3->left = n6;

	Solution sol;
	vector<vector<int> > ans = sol.verticalOrder(n1);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}