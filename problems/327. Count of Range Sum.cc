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
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		// return countRangeSumMergeSort(nums, lower, upper);
		return countRangeSumSegTree(nums, lower, upper);
	}

	// merge sort
    int countRangeSumMergeSort(vector<int>& nums, int lower, int upper) {
        vector<long long> sums(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
        	sums[i] = (i == 0 ? 0 : sums[i - 1]) + nums[i];
        }
        return mergeSort(sums, lower, upper, 0, nums.size() - 1);
    }

    int mergeSort(vector<long long>& sums, int lower, int upper, int lo, int hi) {
    	int n = hi - lo + 1;
    	if (n == 0) return 0;
    	if (n == 1) {
    		if (sums[lo] >= lower && sums[lo] <= upper) return 1;
    		else return 0;
    	}

    	int mid = lo + (hi - lo) / 2;
    	int count = mergeSort(sums, lower, upper, lo, mid) + 
    				mergeSort(sums, lower, upper, mid + 1, hi);

    	int iL = lo, iR = lo;
    	for (int j = mid + 1; j <= hi; j++) {
    		// search for valid [iL, iR], s.t.
    		// lower <= sums[j] - sums[i] <= upper
    		// -> lower + sums[i] <= sums[j] <= upper + sums[i]
    		// where i is from the front half sums, and j is from the latter half sums
    		while (iR <= mid && lower + sums[iR] <= sums[j]) iR++;	// iR - 1 is valid 
    		while (iL <= mid && upper + sums[iL] < sums[j]) iL++;	// iL is valid
    		count += (iR - 1) - iL + 1;
    	}

    	// merge
    	vector<long long> tmp(hi - lo + 1);
    	int pL = lo, pR = mid + 1;
    	for (int i = 0; i < hi - lo + 1; i++) {
    		if (pL > mid) tmp[i] = sums[pR++];
    		else if (pR > hi) tmp[i] = sums[pL++];
    		else tmp[i] = sums[pL] < sums[pR] ? sums[pL++] : sums[pR++];
    	}
    	copy(tmp.begin(), tmp.end(), sums.begin() + lo);
    	return count;
    }

    // segment tree
    vector<long long> tree;
    int n;
    int countRangeSumSegTree(vector<int>& nums, int lower, int upper) {
    	vector<long long> sumsVec(nums.size());
    	for (int i = 0; i < nums.size(); i++) {
    		sumsVec[i] = (i == 0 ? 0 : sumsVec[i - 1]) + nums[i];
    	}
    	sort(sumsVec.begin(), sumsVec.end());
    	map<long long, int> sum2idx;
    	for (auto sum : sumsVec) {
    		if (sum2idx.find(sum) == sum2idx.end()) {
    			sum2idx[sum] = sum2idx.size();
    		}
    	}

    	n = sum2idx.size();
    	tree.resize(n + 1, 0);
    	int count = 0;
    	long long sum = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		sum += nums[i];
    		// lower <= sum - target <= upper
    		// sum - upper <= target <= sum - lower
    		if (lower <= sum && sum <= upper) count++;
    		auto lowerIt = sum2idx.lower_bound(sum - upper);
    		auto upperIt = sum2idx.upper_bound(sum - lower);
    		if (lowerIt != sum2idx.end() && upperIt != sum2idx.begin()) {
    			int lowerSum = lowerIt->second;
    			int upperSum = (--upperIt)->second;
    			count += query(lowerSum, upperSum);
    		}
 			updateTree(sum2idx[sum]);
    	}
    	return count;
    }
    void updateTree(int i) {
    	int idx = i + 1;
    	while (idx <= n) {
    		tree[idx]++;
    		idx += idx & (-idx);
    	}
    }
    // return sums[j] - sums[i - 1]
    int query(int i, int j) {
    	if (i == 0) return getSum(j);
    	return getSum(j) - getSum(i - 1);
    }
    int getSum(int i) {
    	int idx = i + 1;
    	long long sum = 0;
    	while (idx > 0) {
    		sum += tree[idx];
    		idx -= idx & (-idx);
    	}
    	return sum;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> nums = {-3,1,2,-2,2,-1};
	int lower = -3, upper = -1;
	cout << sol.countRangeSum(nums, lower, upper) << endl;

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