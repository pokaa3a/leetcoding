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
    int shortestPathLength(vector<vector<int> >& graph) {
        int n = graph.size();
        int min_length = INT_MAX;

        for (int start = 0; start < n; ++start) {
        	queue<pair<pair<int, int> , int> > q;	// ((cur node, path), length)
        	vector<set<int> > seen(n, set<int>());

        	q.push(make_pair(make_pair(start, (1 << start)), 0));
        	seen[start].insert(1 << start);
        	while (!q.empty()) {
        		int q_size = q.size();
        		for (int i = 0; i < q_size; ++i) {
        			pair<pair<int, int>, int> p = q.front(); q.pop();
        			int cur = p.first.first;
        			int visited = p.first.second;
        			int length = p.second;
        			// cout << "(" << cur << ", " << visited << ", " << length << ")" << endl;
        			if (visited == (1 << n) - 1) {
        				min_length = min(min_length, length);
        			}

        			for (int j = 0; j < graph[cur].size(); ++j) {
        				if (seen[graph[cur][j]].count(visited | (1 << graph[cur][j])) == 0) {
        					q.push(make_pair(make_pair(graph[cur][j], visited | (1 << graph[cur][j])), length + 1));
        					seen[graph[cur][j]].insert(visited | (1 << graph[cur][j]));
        				}
        			}
        		}
        	}
        }
        return min_length;
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
	vector<vector<int> > graph;
	int n0[] = {1};
	graph.push_back(vector<int>(n0, n0 + sizeof(n0) / sizeof(int)));
	int n1[] = {0,2,4};
	graph.push_back(vector<int>(n1, n1 + sizeof(n1) / sizeof(int)));
	int n2[] = {1,3,4};
	graph.push_back(vector<int>(n2, n2 + sizeof(n2) / sizeof(int)));
	int n3[] = {2};
	graph.push_back(vector<int>(n3, n3 + sizeof(n3) / sizeof(int)));
	int n4[] = {1,2};
	graph.push_back(vector<int>(n4, n4 + sizeof(n4) / sizeof(int)));

	cout << sol.shortestPathLength(graph) << endl;

	/* [String] */
	// string str = "";

}