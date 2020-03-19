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
    int partitionDisjoint(vector<int>& A) {
    	int n = A.size();
    	vector<int> max_so_far(n + 1, 0);
    	for (int i = 1; i <= n; i++) {
    		max_so_far[i] = max(max_so_far[i - 1], A[i - 1]);
    	}
    	int min_from_end = INT_MAX;
    	int ans = n;
    	for (int i = n - 1; i >= 1; i--) {
    		min_from_end = min(A[i], min_from_end);
    		if (min_from_end >= max_so_far[i]) ans = min(ans, i);
    	}
    	return ans;
    }
};

// One-pass solution
// class Solution {
// public:
// 	int partitionDisjoint(vector<int>& A) {
// 		int max = A[0], max_candidate = A[0], ans = 1;
// 		for (int i = 0; i < A.size(); i++) {
// 			if (A[i] < max) {
// 				ans = i + 1;
// 				max = max_candidate;
// 			} else if (A[i] > max) {
// 				max_candidate[i] = A[i];
// 			}
// 		}
// 		return ans;
// 	}
// };

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,1,1,0,6,12};
	vector<int> A(a, a + sizeof(a) / sizeof(int));
	cout << sol.partitionDisjoint(A) << endl;

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