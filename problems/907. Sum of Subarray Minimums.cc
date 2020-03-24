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
    int sumSubarrayMins(vector<int>& A) {
        stack<int> stk;
        unordered_map<int, int> count;

        long long ans = 0, x = 0;
        for (int i = 0; i < A.size(); i++) {
        	long long k = 0;
        	while (!stk.empty() && stk.top() >= A[i]) {
        		k += count[stk.top()];
        		// cout << "x substract " << stk.top() << " * " << k << endl;
        		x -= stk.top() * count[stk.top()];
        		stk.pop();
        	}
        	stk.push(A[i]);
        	count[A[i]] = k + 1;
        	x = (x + A[i] * k + A[i]) % MOD;
        	// cout << "add " << x << endl;
        	ans = (ans + x) % MOD;
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {48, 87, 27};
	vector<int> A(a, a + sizeof(a) / sizeof(int));
	cout << sol.sumSubarrayMins(A) << endl;

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