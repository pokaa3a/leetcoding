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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int> >& edges) {
    	int n = edges.size();
    	vector<int> parent(n + 1, 0);
    	vector<int> e1(2, 0), e2(2, 0);

    	for (int i = 0; i < n + 1; ++i) parent[i] = i;

    	for (int i = 0; i < edges.size(); ++i) {
    		int u = edges[i][0];
    		int v = edges[i][1];
    		int p_u = find(u, parent);
    		int p_v = find(v, parent);

    		if (p_v != v) {				// 2 parents
    			e1[0] = u;
    			e1[1] = v;
    		} else if (p_u == p_v)	{	// circle
    			e2[0] = u;
    			e2[1] = v;
    		} else {
    			parent[p_v] = p_u;
    		}
    	}
    	if (e1[0] == 0) return e2;		// no 2 parents
    	if (e2[0] == 0) return e1;		// no circle
    	for (int i = 0; i < n; ++i) {	// circle happend first, then 2 parents
    		if (edges[i][1] == e1[1]) return edges[i];
    	}
    	return vector<int>();
    }
    int find(int x, vector<int>& parent) {
    	if (parent[x] != x) parent[x] = find(parent[x], parent);
    	return parent[x];
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
	const int rows = 5;
	const int cols = 2;
	int arr[rows][cols] = {{1,2},{2,3},{3,4},{4,1},{1,5}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}
	vector<int> ans = sol.findRedundantDirectedConnection(grid);
	cout << ans[0] << ", " << ans[1] << endl;

	/* [String] */
	// string str = "";

}