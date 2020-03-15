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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int treeDiameter(vector<vector<int> >& edges) {
        map<int, vector<int> > tree;
        for (int i = 0; i < edges.size(); ++i) {
        	tree[edges[i][0]].push_back(edges[i][1]);
        	tree[edges[i][1]].push_back(edges[i][0]);
        }

        int res = 0;
        dfs(tree.begin()->first, INT_MAX, tree, res);
        return res;
    }
    int dfs(int node, int parent, map<int, vector<int> >& tree, int& res) {
    	if (tree[node].size() == 1 && tree[node][0] == parent) return 1;

    	int first_max = 0, secnod_max = 0;
    	for (int i = 0; i < tree[node].size(); ++i) {
    		if (tree[node][i] == parent) continue;

    		int depth = dfs(tree[node][i], node, tree, res);

    		if (depth > first_max) {
    			secnod_max = first_max;
    			first_max = depth;
    		} else if (depth > secnod_max) {
    			secnod_max = depth;
    		}
    		res = max(res, first_max + secnod_max);
    	}
    	return first_max + 1;
    }
};

int main() {
	/* Solution */
	Solution sol;

	int e1[] = {0, 1};
	int e2[] = {1, 2};
	int e3[] = {2, 3};
	int e4[] = {1, 4};
	int e5[] = {4, 5};
	vector<vector<int> > edges;
	edges.push_back(vector<int>(e1, e1 + 2));
	edges.push_back(vector<int>(e2, e2 + 2));
	edges.push_back(vector<int>(e3, e3 + 2));
	edges.push_back(vector<int>(e4, e4 + 2));
	edges.push_back(vector<int>(e5, e5 + 2));

	cout << sol.treeDiameter(edges) << endl;
	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

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