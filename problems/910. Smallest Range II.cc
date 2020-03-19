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
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int ans = A.back() - A.front();
        for (int i = 0; i < A.size() - 1; ++i) {
        	int x = max(A[i] + K, A.back() - K);
        	int y = min(A.front() + K, A[i + 1] - K);
        	ans = min(ans, x - y);
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	int arr[] = {1,3,6};
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	int K = 3;
	cout << sol.smallestRangeII(nums, K) << endl;

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