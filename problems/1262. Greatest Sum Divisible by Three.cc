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
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            vector<int> dp2 = dp;
            for (int j = 0; j < 3; ++j) {
                int y = dp2[j];
                dp[(x + y) % 3] = max(dp[(x + y) % 3], x + y);
            }
        }
        return dp[0];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int n[] = {3,6,5,1,8};
	vector<int> nums(n, n + 5);
	cout << sol.maxSumDivThree(nums) << endl;

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