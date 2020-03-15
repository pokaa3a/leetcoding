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
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        for (int i = 0; i <= 9; ++i) {
        	dfs(i, low, high, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    void dfs(long long n, int low, int high, vector<int>& ans) {
    	if (low <= n && n <= high) {
    		ans.push_back((int)n);
    	}
    	if (n == 0 || n > high) return;
    	int last = n % 10;
    	if (last != 0) {
    		dfs(10 * n + last - 1, low, high, ans);
    	}
    	if (last != 9) {
    		dfs(10 * n + last + 1, low, high, ans);
    	}
    }
};


int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int low = 0, high = 21;
	vector<int> ans = sol.countSteppingNumbers(low, high);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

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