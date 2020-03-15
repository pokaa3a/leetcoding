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
    int maximalRectangle(vector<vector<char> >& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<int> > col_sum(m, vector<int>(n, 0));

        int ans = INT_MIN;
        for (int i = 0; i < m; ++i) {
        	stack<int> st;
        	int j = 0;
        	while (j < n) {
        		if (matrix[i][j] == '1') col_sum[i][j] = (i == 0 ? 0 : col_sum[i - 1][j]) + 1;
        		if (st.empty() || col_sum[i][j] >= col_sum[i][st.top()]) st.push(j++);
        		else {
        			int idx = st.top();
        			st.pop();
        			ans = max(ans, (st.empty() ? j : j - 1 - st.top()) * col_sum[i][idx]);
        		}
        	}
        	while (!st.empty()) {
        		int idx = st.top();
        		st.pop();
        		ans = max(ans, (st.empty() ? j : j - 1 - st.top()) * col_sum[i][idx]);
        	}
        }
        return ans;
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
	const int cols = 5;
	char arr[rows][cols] = {{'1','0','1','0','0'}, 
						    {'1','0','1','1','1'},
						    {'1','1','1','1','1'},
							{'1','0','0','1','0'}};
	vector<vector<char> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<char>(arr[r], arr[r] + cols));
	}

	cout << sol.maximalRectangle(grid) << endl;

	/* [String] */
	// string str = "";

}