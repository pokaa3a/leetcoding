#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <list>
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
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> presum;
        vector<int> min_subarray(n, 2 * n);	// min_subarray[i] is the minimum length of a subarray 
        									// whose sum == target from arr[0 ~ i]
        									// min_subarray[i] == 2*n if no such subarray has been found
        presum[0] = -1;
        int sum = 0;
        int res = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int len = 2 * n;    // initialize with a large value
            if (presum.count(sum - target) > 0) {
                len = i - presum[sum - target];
                
                if (presum[sum - target] >= 0 && min_subarray[presum[sum - target]] < 2 * n) {
                    res = min(res, len + min_subarray[presum[sum - target]]);
                }
            }
            min_subarray[i] = i == 0 ? len : min(min_subarray[i - 1], len);
            presum[sum] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	// vector<int> arr = {3,2,2,4,3};
	// vector<int> arr = {7,3,4,7};
	// vector<int> arr = {4,3,2,6,2,3,4};
	// vector<int> arr = {5,5,4,4,5};
	vector<int> arr = {3,1,1,1,5,1,2,1};
	int target = 3;

	cout << sol.minSumOfLengths(arr, target) << endl;
}