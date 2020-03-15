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
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        vector<int> shortest(n, INT_MAX);
        unordered_map<int, vector<int> > m; // val -> [indices]
        for (int i = 0; i < arr.size(); ++i) {
        	m[arr[i]].push_back(i);
        }
        shortest[0] = 0;
        queue<int> q;
        q.push(0);

        int step = 1;
        while (!q.empty()) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; i++) {
        		int idx = q.front();
        		q.pop();

        		if (idx == n - 1) return shortest.back();

        		if (idx - 1 >= 0 && shortest[idx - 1] > step) {
        			shortest[idx - 1] = step;
        			q.push(idx - 1);
        		}
        		if (idx + 1 < n && shortest[idx + 1] > step) {
        			shortest[idx + 1] = step;
        			q.push(idx + 1);
        		}
        		for (int j = 0; j < m[arr[idx]].size(); j++) {
        			int possible_idx = m[arr[idx]][j];
        			if (shortest[possible_idx] > step) {
        				shortest[possible_idx] = step;
        				q.push(possible_idx);
        			}
        		}
        		m[arr[idx]] = vector<int>();
        	}
        	step++;
        }
        return shortest.back();
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