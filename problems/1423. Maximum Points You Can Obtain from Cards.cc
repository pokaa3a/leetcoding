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
    int maxScore(vector<int>& cardPoints, int k) {
        int res = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);

        int n = cardPoints.size();
        int front_idx = k - 1, end_idx = n - 1;
        int sum = res;
        for (int i = 0; i < k; i++) {
        	sum -= cardPoints[front_idx--];
        	sum += cardPoints[end_idx--];
        	res = max(res, sum);
        }
        return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<int> cardPoints = {9,7,7,9,7,7,9};
	int k = 7;
	cout << sol.maxScore(cardPoints, k) << endl;

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