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
	vector<vector<vector<int> > > dp;
public:
    int catMouseGame(vector<vector<int> >& graph) {
    	int n = graph.size();
        // dp[t][m][c]: (t, m, c) = (steps, mouse position, cat position)
        // state: (0, 1, 2) = (draw, mouse wins, cat wins)
        dp = vector<vector<vector<int> > >(2 * n, vector<vector<int> >(n, vector<int>(n, -1)));
        return dfs(graph, 0, 1, 2);
    }
    int dfs(vector<vector<int> >& graph, int t, int m, int c) {
    	if (t == graph.size() * 2) return 0;
    	if (m == c) return dp[t][m][c] = 2;
    	if (m == 0) return dp[t][m][c] = 1;
    	if (dp[t][m][c] != -1) return dp[t][m][c];

    	if (t % 2 == 0) {		// mouse's turn
    		bool flag = true;	// all children are 2
    		for (int i = 0; i < graph[m].size(); ++i) {
    			int child = dfs(graph, t + 1, graph[m][i], c);
    			if (child == 1) return dp[t][m][c] = 1;
    			else if (child != 2) flag = false;
    		}
    		if (flag) return dp[t][m][c] = 2;
    		else return dp[t][m][c] = 0;
    	} else {				// cat's turn
    		bool flag = true;	// all children are 1
    		for (int i = 0; i < graph[c].size(); ++i) {
    			if (graph[c][i] == 0) continue;
    			int child = dfs(graph, t + 1, m, graph[c][i]);
    			if (child == 2) return dp[t][m][c] = 2;
    			else if (child != 1) flag = false;
    		}
    		if (flag) return dp[t][m][c] = 1;
    		else return dp[t][m][c] = 0;
    	}
    	return 0;
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