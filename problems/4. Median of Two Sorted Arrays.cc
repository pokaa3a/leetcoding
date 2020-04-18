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

// https://youtu.be/LPFhl65R7ww

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    	int len_1 = nums1.size(), len_2 = nums2.size();
    	int lo = 0, hi = len_1;
    	while (lo <= hi) {
    		// partition_1 + partiaion_2 == (len_1 + len_2 + 1) / 2
    		int partition_1 = lo + (hi - lo) / 2;
    		int partition_2 = (len_1 + len_2 + 1) / 2 - partition_1;

    		int max_1 = partition_1 == 0 ? INT_MIN : nums1[partition_1 - 1];
    		int max_2 = partition_2 == 0 ? INT_MIN : nums2[partition_2 - 1];
    		int min_1 = partition_1 == len_1 ? INT_MAX : nums1[partition_1];
    		int min_2 = partition_2 == len_2 ? INT_MAX : nums2[partition_2];

    		if (max_1 <= min_2 && max_2 <= min_1) {
    			if ((len_1 + len_2) % 2 == 1) {
    				return max(max_1, max_2);
    			} else {
    				return ((double)max(max_1, max_2) + (double)min(min_1, min_2)) / 2;
    			}
    		} else if (max_1 > min_2) {
    			hi = partition_1 - 1;
    		} else {
    			lo = partition_1 + 1;
    		}
    	}
    	return 0.0;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> nums1 = {1,3,5,7};
	vector<int> nums2 = {2,3,4,8};

	sol.findMedianSortedArrays(nums1, nums2);

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