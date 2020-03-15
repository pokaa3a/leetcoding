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
    int maxJumps(vector<int>& arr, int d) {
    	int n = arr.size();
        vector<pair<int, int> > v;
        for (int i = 0; i < arr.size(); ++i) v.push_back(make_pair(arr[i], i));
        sort(v.begin(), v.end());

        vector<int> dp(n, 1);
        // int ans = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
        	int h = v[i].first;
        	int idx = v[i].second;

        	// left side
        	for (int j = idx - 1; j >= max(0, idx - d); --j) {
        		if (arr[j] < h) dp[j] = max(dp[j], dp[idx] + 1);
        		else break;
        	}
        	// right side
        	for (int j = idx + 1; j <= min(n - 1, idx + d); ++j) {
        		if (arr[j] < h) dp[j] = max(dp[j], dp[idx] + 1);
        		else break;
        	}
        	// ans = max(ans, dp[idx]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {59,8,74,27,92,36,95,78,73,54,75,37,42,15,59,84,66,25,35,61,97,16,6,52,49,18,22,70,5,59,92,85};
	int n = sizeof(a) / sizeof(int);
	vector<int> arr(a, a + n);
	int d = 20;

	cout << sol.maxJumps(arr, d) << endl;

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