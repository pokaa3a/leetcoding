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
	unordered_map<int, int> record;
	int power(int x) {
		if (x == 1) return 0;

		if (record.find(x) != record.end()) return record[x];
		int a;
		if (x & 1) {
			a = power(3 * x + 1) + 1;
		} else {
			a = power(x / 2) + 1;
		}
		record[x] = a;
		return a;
	}
    int getKth(int lo, int hi, int k) {
    	vector<pair<int, int> > v;
    	for (int i = lo; i <= hi; i++) {
    		int p = power(i);
    		v.push_back(make_pair(p, i));
    	}
    	sort(v.begin(), v.end());
    	return v[k - 1].second;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int lo = 1, hi = 1000, k = 777;
	cout << sol.getKth(lo, hi, k) << endl;

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