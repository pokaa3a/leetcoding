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
    int threeSumMulti(vector<int>& A, int target) {
    	vector<long long> count(101);
    	for (int i = 0; i < A.size(); i++) {
    		count[A[i]]++;
    	}

    	long long ans = 0;
    	for (int i = 0; i <= 100; ++i) {
    		for (int j = i; j <= 100; ++j) {
    			int k = target - i - j;
    			if (k < j || k > 100) continue;

    			if (i != j && j != k) {
    				ans += count[i] * count[j] * count[k];
    			} else if (i == j && j != k) {
    				// choose 2 from count[i] elements
    				ans += count[i] * (count[i] - 1) / 2 * count[k];
    			} else if (i != j && j == k) {
    				// choose 2 from count[j] elements
    				ans += count[i] * count[j] * (count[j] - 1) / 2;
    			} else {
    				// choose 3 from count[i] elements
    				ans += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
    			}
    			ans %= MOD;
    		}
    	}
    	return int(ans % MOD);
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,1,2,2,2,2}, target = 5;
	vector<int> A(a, a + sizeof(a) / sizeof(int));

	cout << sol.threeSumMulti(A, target) << endl;

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