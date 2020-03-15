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

// The trick here is:
// sum[i ~ j] = sum[0 ~ j] - sum[0 ~ i]
// So we don't need to record (x, i) if we have (y, j), s.t. x > y and i < j
// Because when we at index j, we are aiming for i, s.t. sum[i ~ j] >= K
// We don't need (x', i') s.t. x' > x and i' < i
// 
// Depending on the design, we may also use binary search for this problem

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
    	deque<pair<int, int> > dq;
    	int sum = 0, ans = INT_MAX;

    	for (int i = 0; i < A.size(); ++i) {
    		sum += A[i];
    		if (sum >= K) ans = min(ans, i + 1);
    		while (!dq.empty() && dq.back().first > sum) dq.pop_back();
    		while (!dq.empty() && sum - dq.front().first >= K) {
    			ans = min(ans, i - dq.front().second);
    			dq.pop_front();
    		}

    		dq.push_back(make_pair(sum, i));
    	}
    	return ans == INT_MAX ? -1 : ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {2,-1,2};
	int n = sizeof(a) / sizeof(int);
	vector<int> A(a, a + n);
	int K = 3;

	cout << sol.shortestSubarray(A, K) << endl;

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