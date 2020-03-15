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
    double frogPosition(int n, vector<vector<int> >& edges, int t, int target) {
        vector<vector<int> > tree(n + 1, vector<int>());
        for (int i = 0; i < edges.size(); ++i) {
        	int from = edges[i][0];
        	int to = edges[i][1];

        	tree[from].push_back(to);
        	tree[to].push_back(from);
        }
        tree[0].push_back(-1);
        tree[0].push_back(1);
        tree[1].push_back(0);

        queue<pair<int, double> > q; // (vertex, prob)
        unordered_set<int> visited;
        q.push(make_pair(0, 1.0));
        visited.insert(-1);
        visited.insert(0);

        double ans = 0;
        for (int tt = 0; tt <= t; ++tt) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; ++i) {
        		pair<int, double> p = q.front(); q.pop();

        		int v = p.first;
        		double prev_prob = p.second;

        		// cout << "v: " << v << endl;
        		// cout << "prev_prob: " << prev_prob << endl;
        		for (int j = 0; j < tree[v].size(); j++) {
        			if (visited.count(tree[v][j]) > 0) continue;
        			// cout << "next: " << tree[v][j] << endl;
        			double prob = prev_prob * 1.0 / double(tree[v].size() - 1);
        			// cout << "prob: " << prob << endl;

        			if (tree[v][j] == target) {
        				if (tt == t) {
        					ans = prob;

        				} else {
        					if (tree[target].size() == 1) ans = prob;
        					else ans = 0;
        				}
        				return ans;
        			}
        			q.push(make_pair(tree[v][j], prob));
        			visited.insert(tree[v][j]);
        		}
        	}
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}