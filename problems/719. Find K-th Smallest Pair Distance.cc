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
	int NumPairsWithDistanceLessThanOrEqualTo(vector<int>& nums, int diff) {
		int count = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			int target = nums[i] + diff;
			int idx = upper_bound(nums.begin() + i, nums.end(), target) - nums.begin();
			// cout << "target: " << target << " add " << idx - i << endl;
			count += idx - i - 1;
		}
		return count;
	}

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums.front();
        // look for smallest diff s.t. countDistance(diff) >= k
        while (l < r) {
        	int diff = l + (r - l) / 2;
        	int count = NumPairsWithDistanceLessThanOrEqualTo(nums, diff);

        	// cout << "diff: " << diff << " count: " << count << endl;

        	if (count < k) {		// diff is too small
        		l = diff + 1;
        	} else {			// diff is too large
        		r = diff;
        	}
        }
        return l;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {1,6,1};
	int n = sizeof(a) / sizeof(int);
	vector<int> arr(a, a + n);

	int k = 3;
	cout << sol.smallestDistancePair(arr, k) << endl;

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