#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxLevelSum(TreeNode* root) {
		long long max_sum = root->val;
		int min_lv = 1, cur_lv = 1;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int q_size = q.size();
			long long cur_sum = 0;
			cur_lv++;
			for (int i = 0; i < q_size; ++i) {
				TreeNode* cur = q.front();
				q.pop();

				if (cur->left) {
					cur_sum += cur->left->val;
					q.push(cur->left);
				}
				if (cur->right) {
					cur_sum += cur->right->val;
					q.push(cur->right);
				}
			}
			if (cur_sum > max_sum) {
				max_sum = cur_sum;
				min_lv = cur_lv;
			}
		}
		return min_lv;
	}
};

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(7);
	TreeNode* n3 = new TreeNode(0);
	TreeNode* n4 = new TreeNode(7);
	TreeNode* n5 = new TreeNode(-8);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

	Solution sol;
	cout << sol.maxLevelSum(n1) << endl;
}