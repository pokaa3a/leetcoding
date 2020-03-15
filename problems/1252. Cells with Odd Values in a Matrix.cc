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
    int oddCells(int n, int m, vector<vector<int> >& indices) {
        vector<vector<int> > mat(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < indices.size(); ++i) {
        	int r = indices[i][0];
        	int c = indices[i][1];
        	for (int j = 0; j < m; ++j) {
        		if (++mat[r][j] % 2 == 1) ans++;
        		else ans--;
        	}
        	for (int j = 0; j < n; ++j) {
        		if (++mat[j][c] % 2 == 1) ans++;
        		else ans--;
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