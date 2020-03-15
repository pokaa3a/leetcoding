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
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int> > tree;

        for (int id = 0; id < n; ++id) {
        	int manager_id = manager[id];
        	if (tree.find(manager_id) == tree.end()) {
        		tree[manager_id] = vector<int>();
        	}
        	tree[manager_id].push_back(id);
        }

        // BFS
        int time = 0;
        queue<pair<int, int> > q;	// (id, informed_time)
        q.push(make_pair(headID, 0));

        while (!q.empty()) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; ++i) {
        		pair<int, int> p = q.front(); q.pop();
        		int id = p.first;
        		int informed_time = p.second;
        		time = max(time, informed_time);

        		for (int j = 0; j < tree[id].size(); ++j) {
        			q.push(make_pair(tree[id][j], informed_time + informTime[id]));
        		}
        	}
        }
        return time;
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