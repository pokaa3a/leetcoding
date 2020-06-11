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
	unordered_map<string, vector<pair<string, double>>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    	for (int i = 0; i < equations.size(); i++) {
    		graph[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
    		graph[equations[i][1]].push_back(make_pair(equations[i][0], 1 / values[i]));
    	}
    	vector<double> res;
    	for (auto q : queries) {
    		res.push_back(calc(q[0], q[1]));
    	}
    	return res;
    }
    double calc(string src, string dst) {
    	if (graph.count(src) == 0 || graph.count(dst) == 0) return -1.0;
    	unordered_set<string> visited;
    	queue<pair<string, double>> q;
    	q.push(make_pair(src, 1.0));
    	visited.insert(src);

    	while (!q.empty()) {
    		int q_size = q.size();
    		for (int i = 0; i < q_size; i++) {
    			auto cur = q.front();
    			q.pop();

    			if (cur.first == dst) return cur.second;

    			for (auto next : graph[cur.first]) {
    				if (visited.count(next.first) == 0) {
    					visited.insert(next.first);
    					q.push(make_pair(next.first, cur.second * next.second));
    				}
    			}
    		}
    	}
    	return -1.0;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
	vector<double> values = {2.0, 3.0};
	vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"},
									  {"a", "a"}, {"x", "x"}};
	vector<double> res = sol.calcEquation(equations, values, queries);
	for (auto d : res) cout << d << endl;

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