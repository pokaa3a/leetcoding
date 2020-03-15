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
	double maximumAverageSubtree(TreeNode* root) {
		int n_nodes;
		double max_avg;
		double avg = compute(root, n_nodes, max_avg);
		return max_avg;
	}
private:
	double compute(TreeNode* root, int& n_nodes, double& max_avg) {
		if (!root) {
			n_nodes = 0;
			max_avg = 0;
			return 0.0;
		}
		int left_n_nodes, right_n_nodes;
		double left_max_avg, right_max_avg;
		double left_avg = compute(root->left, left_n_nodes, left_max_avg);
		double right_avg = compute(root->right, right_n_nodes, right_max_avg);

		double this_avg = ((double)root->val + left_avg * (double)left_n_nodes + right_avg * (double)right_n_nodes) / double(left_n_nodes + right_n_nodes + 1);
		n_nodes = left_n_nodes + right_n_nodes + 1;
		max_avg = max(this_avg, max(left_max_avg, right_max_avg));
		return this_avg;
	}
};

int main() {
	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(6);
	TreeNode* n3 = new TreeNode(1);
	n1->left = n2;
	n1->right = n3;

	Solution sol;
	cout << sol.maximumAverageSubtree(n1) << endl;
}