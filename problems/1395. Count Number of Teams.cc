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
    int numTeams(vector<int>& rating) {
    	int ans = 0;
    	for (int i = 0; i < rating.size(); i++) {
    		int t = rating[i];
    		int left_larger = larger(0, i - 1, t, rating);
    		int left_smaller = smaller(0, i - 1, t, rating);
    		int right_larget = larger(i + 1, rating.size() - 1, t, rating);
    		int right_smaller = smaller(i + 1, rating.size() - 1, t, rating);
    		ans += left_larger * right_smaller + left_smaller * right_larget;
    	}
    	return ans;
    }
    int larger(int start, int end, int target, vector<int>& rating) {
    	if (end < start) return 0;
    	int count = 0;
    	for (int i = start; i <= end; i++) {
    		if (rating[i] > target) count++;
    	}
    	return count;
    }
    int smaller(int start, int end, int target, vector<int>& rating) {
    	if (end < start) return 0;
    	int count = 0;
    	for (int i = start; i <= end; i++) {
    		if (rating[i] < target) count++;
    	}
    	return count;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

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