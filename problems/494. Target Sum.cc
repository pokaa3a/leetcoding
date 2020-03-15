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

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
        	unordered_map<int, int> tmp;
        	for (unordered_map<int, int>::iterator it = dp.begin(); it != dp.end(); it++) {
        		tmp[it->first + nums[i]] += it->second;
        		tmp[it->first - nums[i]] += it->second;
        	}
        	dp = tmp;
        }
        return dp[S];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n[] = {1,1,1,1,1}, S = 3;
	vector<int> nums(n, n + 5);
	cout << sol.findTargetSumWays(nums, S) << endl;

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