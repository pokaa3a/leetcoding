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
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        assert (n % 2 == 0);
        int even_idx = 0, odd_idx = 1;

        while (even_idx < n && odd_idx < n) {
        	if (A[even_idx] % 2 == 0) {
        		even_idx += 2;
        		continue;
        	}
        	if (A[odd_idx] % 2 != 0) {
        		odd_idx += 2;
        		continue;
        	}
        	swap(A[even_idx], A[odd_idx]);
        	even_idx += 2;
        	odd_idx += 2;
        }
        return A;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {4,2,5,7};
	vector<int> A(a, a + sizeof(a) / sizeof(int));
	vector<int> res = sol.sortArrayByParityII(A);

	for (int i = 0; i < res.size(); i++) cout << res[i] << " ";

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