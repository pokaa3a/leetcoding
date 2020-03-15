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
    TreeNode* recoverFromPreorder(string S) {
        return helper(S, 0, 0);
    }
private:
	TreeNode* helper(string& S, int depth, int& start) {
		if (start >= S.size()) return NULL;
		int num_i = start + depth;
		for (int i = start; i < min(S.size(), num_i); ++i) {
			if (S[i] != '-') return NULL;
		}
		
		int dash_i = S.find("-", num_i);
		int num = stoi(S.substr(num_i, dash_i));

		TreeNode* root = new TreeNode(num);
		root->left = helper(S, depth + 1, dash_i);
		root->right = helper(S, depth + 1, dash_i);
		start = dash_i;
	}
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}