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
// Ref: https://www.geeksforgeeks.org/bridge-in-a-graph/?fbclid=IwAR3gh1CtdCjBlbI9-yxk8NkXmIABgzXdJSjTLxYGeFcrz23oXopXkQW3wTI
class Solution {
public:
    vector<vector<int> > criticalConnections(int n, vector<vector<int> >& connections) {
        vector<vector<int> > bridges;
        vector<vector<int> > adj(n, vector<int>());
        for (int i = 0; i < connections.size(); ++i) {
        	int u = connections[i][0], v = connections[i][1];
        	adj[u].push_back(v);
        	adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<int> disc(n, INT_MAX), low(n, INT_MAX), parent(n, INT_MAX);

        int time = 0;

        dfs(0, adj, visited, disc, low, parent, bridges, time);
        return bridges;
    }
    // u: The vertex to be visited next
    // visited: Keeps tract of visited vertices
    // disc[v]: Discovery times of vertice v in DFS
    // low[v]: Earliest discovery time among all visited vertex in the subtree rooted with v
    // parent: Parent vertices in DFS tree

    // Condition for an edge u->v (the direction here is the visiting order in DFS) to be 
    // a bridge is low[v] > disc[u], which means the earliest dicovery time that v has
    // is later than the discovery time of u, so there is only one way from u to v.

    void dfs(int u, vector<vector<int> >& adj, vector<bool>& visited, vector<int>& disc, vector<int>& low,
    		 vector<int>& parent, vector<vector<int> >& bridges, int& time) {
    	visited[u] = true;
    	disc[u] = low[u] = ++time;

    	for (int i = 0; i < adj[u].size(); ++i) {
    		int v = adj[u][i];

    		if (!visited[v]) {
    			parent[v] = u;
    			dfs(v, adj, visited, disc, low, parent, bridges, time);

    			low[u] = min(low[u], low[v]);
    			if (low[v] > disc[u]) {
    				bridges.push_back({u, v});
    			}
    		} else if (v != parent[u]) {
    			low[u] = min(low[u], low[v]);
    		}
    	}
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	const int rows = 4;
	const int cols = 2;
	int arr[rows][cols] = {{0,1},{1,2},{2,0},{1,3}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	int n = 4;
	vector<vector<int> > bridges = sol.criticalConnections(n, grid);
	for (int i = 0; i < bridges.size(); ++i) {
		cout << bridges[i][0] << ", " << bridges[i][1] << endl;
	}

	/* [String] */
	// string str = "";

}