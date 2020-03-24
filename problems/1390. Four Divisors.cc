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
    int sumFourDivisors(vector<int>& nums) {
    	int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
        	int x = nums[i], num_div = 0, div = 0;
        	for (int k = 2; k * k <= x; k++) {
        		if (x % k == 0) {
        			if (num_div > 0) {
        				num_div++;
        				break;
        			}
        			div = k;
        			num_div++;
        		}
        	}
        	if (num_div == 1 && div != x / div) ans += 1 + x + div + x / div;
        }
        return ans;
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