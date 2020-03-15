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
    int minSetSize(vector<int>& arr) {
    	int at_least = (arr.size() + 1) / 2;
    	unordered_map<int, int> freq;
    	for (int i = 0; i < arr.size(); ++i) {
    		freq[arr[i]]++;
    	}

    	vector<int> count;
    	for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
    		count.push_back(it->second);
    	}
    	sort(count.begin(), count.end());

    	int num_set = 0, num_rm = 0;
    	for (int i = count.size() - 1; i >= 0; --i) {
    		num_set++;
    		num_rm += count[i];
    		if (num_rm >= at_least) break;
    	}
    	return num_set;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int a[] = {3,3,3,3,5,5,5,2,2,7};
	int n = sizeof(a) / sizeof(int);

	vector<int> arr(a, a + n);
	cout << sol.minSetSize(arr) << endl;

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