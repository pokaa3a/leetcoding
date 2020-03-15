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

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size() - 1);
    }

    TreeNode* construct(vector<int>& preorder, int left, int right) {
    	cout << "lft: " << left << " rht: " << right << endl;
    	TreeNode* root = new TreeNode(preorder[left]);

    	if (left == right) return root;

    	int bigger = upper_bound(preorder.begin() + left + 1, preorder.begin() + right + 1, preorder[left]) - preorder.begin();
    	
    	cout << "bigger: " << bigger << endl;
    	if (bigger > left + 1) root->left = construct(preorder, left + 1, bigger - 1);
    	if (bigger <= right) root->right = construct(preorder, bigger, right);
    	return root;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int p[] = {4, 2};
	vector<int> preorder(p, p + 2);
	TreeNode* root = sol.bstFromPreorder(preorder);

}