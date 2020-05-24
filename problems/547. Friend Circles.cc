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
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> group(M.size());
        for (int i = 0; i < M.size(); i++) group[i] = i;
        
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                if (i == j) continue;
                if (M[i][j]) {
                    unify(i, j, group);
                }
            }
        }
        unordered_set<int> unique;
        for (int i = 0; i < M.size(); i++) {
            unique.insert(find(i, group));
        }
        return unique.size();
    }
    int find(int x, vector<int>& group) {
        if (x != group[x]) group[x] = find(group[x], group);
        return group[x];
    }
    void unify(int x, int y, vector<int>& group) {
        int a = find(x, group);
        int b = find(y, group);
        if (a != b) group[a] = b;
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