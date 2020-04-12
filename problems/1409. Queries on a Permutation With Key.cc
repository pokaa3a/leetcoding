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
// O(qm)
/*
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> position(m + 1, 0);
        for (int i = 1; i <= m; i++) {
        	position[i] = i - 1;
        }

        vector<int> output;
        for (int q : queries) {
        	output.push_back(position[q]);
        	int ref = position[q];
        	for (int& p : position) {
        		if (p < ref) {
        			p++;
        		}
        	}
        	position[q] = 0;
        }
        return output;
    }
};
*/

// O(qlogm)
class Solution {
public:
	vector<int> tree;
    int n;
    vector<int> processQueries(vector<int>& queries, int m) {
        tree.resize(2 * m + 1);
    	n = 2 * m;
    	unordered_map<int, int> val2idx;
    	for (int i = 1; i <= m; i++) {
    		val2idx[i] = m + i;
    		update(m + i, 1);
    	}

    	vector<int> output;
    	int cur = m - 1;
    	for (int q : queries) {
    		int idx = val2idx[q];
    		int rank = idx == 0 ? 0 : getSum(idx - 1);
    		output.push_back(rank);

    		val2idx[q] = cur;
    		update(idx, -1);
    		update(cur--, 1);
    	}
    	return output;
    }
    void update(int i, int val) {
    	int idx = i + 1;
    	while (idx <= n) {
    		tree[idx] += val;
    		idx += idx & (-idx);
    	}
    }
    int getSum(int i) {
    	int idx = i + 1;
    	int sum = 0;
    	while (idx > 0) {
    		sum += tree[idx];
    		idx -= idx & (-idx);
    	}
    	return sum;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> queries = {7,5,5,8,3};
	int m = 8;
	vector<int> res = sol.processQueries(queries, m);
	for (int x : res) cout << x << " ";
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