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
// Floyd Warshall
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    	vector<vector<bool>> table(n, vector<bool>(n, false));

    	for (auto p : prerequisites) {
    		table[p[0]][p[1]] = true;
    	}

    	for (int k = 0; k < n; k++) {
    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < n; j++) {
    				if (table[i][k] & table[k][j]) {
    					table[i][j] = true;
    					cout << "connect " << i << " and " << j << endl;
    				}
    			}
    		}
    	}

    	vector<bool> res;
    	for (auto q : queries) {
    		res.push_back(table[q[0]][q[1]]);
    	}
        return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n = 4;
	vector<vector<int>> prerequisites = {{0,1}, {1,2}, {2,3}};
	vector<vector<int>> queries = {{0,3}};

	vector<bool> res = sol.checkIfPrerequisite(n, prerequisites, queries);
	for (auto x : res) cout << x << " ";
}