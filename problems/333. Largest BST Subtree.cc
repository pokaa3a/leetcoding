#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
		int max, min, count;
		myCheck(root, min, max, count);
		return count;
    }
private:
	bool myCheck(TreeNode *root, int& minimum, int& maximum, int& count) {
		if (!root) {
		    minimum = INT_MAX;
			maximum = INT_MIN;
			count = 0;
			return true;
		}
		int left_count, right_count, left_min, left_max, right_min, right_max;
		bool left_check = myCheck(root->left, left_min, left_max, left_count);
		bool right_check = myCheck(root->right, right_min, right_max, right_count);
		if (left_check && right_check && root->val > left_max && root->val < right_min) {
			count = left_count + right_count + 1;
			minimum = min(root->val, left_min);
			maximum = max(root->val, right_max);
			return true;
		}
		count = max(left_count, right_count);
		return false;
	}
};

int main() {
	TreeNode* n1 = new TreeNode(10);
	TreeNode* n2 = new TreeNode(5);
	TreeNode* n3 = new TreeNode(15);
	TreeNode* n4 = new TreeNode(1);
	TreeNode* n5 = new TreeNode(8);
	TreeNode* n6 = new TreeNode(7);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->right = n6;

	Solution sol;
	cout << sol.largestBSTSubtree(n1) << endl;
}