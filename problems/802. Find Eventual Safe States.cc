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
	vector<int> status;	// 0: unvisited, 1: safe, 2: unsafe
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        status.resize(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
        	if (dfs(i, graph)) ans.push_back(i);
        }
        return ans;
    }
    bool dfs(int node, vector<vector<int>>& graph) {
    	if (status[node] != 0) return status[node] == 1;

    	status[node] = 2;
    	for (int next : graph[node]) {
    		if (!dfs(next, graph)) return false;
    	}
    	status[node] = 1;
    	return true;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<vector<int>> graph = {{1,2}, {2,3}, {5} ,{0}, {5}, {}, {}};
	vector<int> ans = sol.eventualSafeNodes(graph);
	for (int x : ans) cout << x << " ";
	cout << endl;

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