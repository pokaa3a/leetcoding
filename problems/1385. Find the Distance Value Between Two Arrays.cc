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
// O(nlogn)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int i = 0; i < arr1.size(); i++) {
        	int n = arr1[i];
            if (upper_bound(arr2.begin(), arr2.end(), n + d) == lower_bound(arr2.begin(), arr2.end(), n - d)) ++ans;
        }
        return ans;
    }
};

// O(n): Bucket

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a1[] = {4,5,8}, a2[] = {10,9,1,8};
	vector<int> arr1(a1, a1 + sizeof(a1) / sizeof(int)), arr2(a2, a2 + sizeof(a2) / sizeof(int));
	int d = 2;
	cout << sol.findTheDistanceValue(arr1, arr2, d) << endl;

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