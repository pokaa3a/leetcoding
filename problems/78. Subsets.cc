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
    vector<vector<int> > subsets(vector<int>& nums) {
        return dfs(0, nums);
    }

    vector<vector<int> > dfs(int idx, vector<int>& nums) {
    	if (idx == nums.size()) return vector<vector<int> >(1, vector<int>());

    	vector<vector<int> > ans;
    	vector<vector<int> > sets = dfs(idx + 1, nums);
    	for (int i = 0; i < sets.size(); ++i) {
    		ans.push_back(sets[i]);
    		sets[i].push_back(nums[idx]);
    		ans.push_back(sets[i]);
    	}
    	return ans;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);
	int n[] = {1,2,3};
	vector<int> nums(n, n + 3);

	vector<vector<int> > ans = sol.subsets(nums);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

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