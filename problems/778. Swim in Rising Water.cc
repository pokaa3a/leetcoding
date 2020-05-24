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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> group(n * n);
        unordered_map<int, pair<int, int>> mp;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                mp[grid[r][c]] = make_pair(r, c);
                group[r * n + c] = r * n + c;
            }
        }
        
        for (int t = 0; t < n * n; t++) {
            int r = mp[t].first, c = mp[t].second;
            int dirs[] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int r_n = r + dirs[k], c_n = c + dirs[k + 1];
                if (r_n >= 0 && r_n < n && c_n >= 0 && c_n < n &&
                    grid[r_n][c_n] < t) {
                    unify(r * n + c, r_n * n + c_n, group);
                }
            }
            if (find(0, group) == find(n * n - 1, group)) return t;
        }
        return 0;
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