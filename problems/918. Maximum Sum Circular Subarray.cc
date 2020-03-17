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
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> back_sum_max(n);

        int back_sum = 0, back_max = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
        	back_sum += A[i];
        	back_max = max(back_max, back_sum);
        	back_sum_max[i] = back_max;
        }

        int front_sum = 0, front_min = 0, ans = INT_MIN;
        for (int i = 0; i < n; i++) {
        	front_sum += A[i];
        	int possible_max_1 = front_sum - front_min;
        	int possible_max_2 = front_sum + (i == n - 1 ? 0 : back_sum_max[i + 1]);
        	ans = max(ans, max(possible_max_1, possible_max_2));
        	front_min = min(front_min, front_sum);
        	
        }
        return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {3,-2,2,-3};
	vector<int> A(a, a + sizeof(a) / sizeof(int));
	cout << sol.maxSubarraySumCircular(A) << endl;

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