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
	// Positive: counter clockwise
	// Negative: clockwise
	int cross_product(vector<int>& O, vector<int>& A, vector<int>& B) {
		return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
	}

    vector<vector<int> > outerTrees(vector<vector<int> >& points) {
        int n = points.size();
        if (n <= 3) return points;
        
    	sort(points.begin(), points.end());
    	int k = 0;

    	vector<vector<int> > ans(2 * n, vector<int>(2, 0));

    	// Build lower hull
    	for (int i = 0; i < n; i++) {
    		while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], points[i]) < 0) k--;
    		ans[k++] = points[i];
    	}

    	// Build upper hull
    	for (int i = n - 2, t = k + 1; i >= 0; i--) {
    		while (k >= t && cross_product(ans[k - 2], ans[k - 1], points[i]) < 0) k--;
    		ans[k++] = points[i];
    	}
    	ans.resize(k-1);
    	return ans;
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