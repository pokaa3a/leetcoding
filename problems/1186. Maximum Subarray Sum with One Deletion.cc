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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int maximumSum(vector<int>& arr) {
    	int n = arr.size();
    	vector<int> fw(n, 0);
    	vector<int> bw(n, 0);
    	int cur_sum = -1e-9;
    	int best_sum = INT_MIN;
    	for (int i = 0; i < n; ++i) {
    		cur_sum = max(arr[i], cur_sum + arr[i]);
    		best_sum = max(best_sum, cur_sum);
    		fw[i] = cur_sum;
    		// cout << "fw[" << i << "]: " << fw[i] << endl;
    	}
    	cur_sum = -1e-9;
    	for (int i = n - 1; i >= 0; --i) {
    		cur_sum = max(arr[i], cur_sum + arr[i]);
    		best_sum = max(best_sum, cur_sum);
    		bw[i] = cur_sum;
    		// cout << "bw[" << i << "]: " << bw[i] << endl;
    	}
    	for (int i = 1; i < n - 1; ++i) {
    		best_sum = max(best_sum, fw[i - 1] + bw[i + 1]);
    	}
    	return best_sum;
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	int arr[] = {11,-10,-11,8,7,-6,9,4,11,6,5,0};
	vector<int> nums(arr, arr + 12);
	cout << sol.maximumSum(nums) << endl;

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