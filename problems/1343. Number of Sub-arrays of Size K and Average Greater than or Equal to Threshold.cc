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
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int cur = accumulate(arr.begin(), arr.begin() + k - 1, 0);
        int ans = 0;

        for (int i = k - 1; i < n; ++i) {
        	cur += arr[i];
        	if (cur >= k * threshold) ans++;
        	cur -= arr[i - k + 1];
        }
        return ans;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {11,13,17,23,29,31,7,5,2,3}, k = 3, threshold = 5;
	int n = sizeof(a) / sizeof(int);
	vector<int> arr(a, a + n);
	cout << sol.numOfSubarrays(arr, k, threshold) << endl;

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