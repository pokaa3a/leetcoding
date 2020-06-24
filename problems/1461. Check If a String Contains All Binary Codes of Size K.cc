#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> pool;
        for (int i = 0; i + k <= s.size(); i++) {
        	string sub = s.substr(i, k);
        	pool.insert(sub);
        }
        return pool.size() == pow(2, k);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s = "0110";
	int k = 2;
	cout << sol.hasAllCodes(s, k) << endl;

}