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
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> empties;
        unordered_map<int, int> lakes;
        vector<int> ans(n, 1);
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                empties.insert(i);
            } else {
                if (lakes.count(rains[i]) > 0) {
                    auto it = empties.upper_bound(lakes[rains[i]]);
                    if (it == empties.end()) return vector<int>();
                    
                    ans[*it] = rains[i];
                    empties.erase(it);
                }
                lakes[rains[i]] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	// vector<int> rains = {1,2,3,4};
	// vector<int> rains = {1,2,0,0,2,1};
	// vector<int> rains = {69,0,0,0,69};
	// vector<int> rains = {10,20,20};
	// vector<int> rains = {0,1,1};
	// vector<int> rains = {1,0,2,0,2,1};
	vector<int> rains = {2,3,0,0,3,1,0,1,0,2,2};

	vector<int> ans = sol.avoidFlood(rains);
	for (int x : ans) cout << x << " ";
	cout << endl;
}