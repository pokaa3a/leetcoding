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
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int assigned = (1 << n) - 1;

        // people[i][j] == ith hat have be assigned to jth person
        vector<vector<int>> people(41, vector<int>());
        vector<vector<long long>> memo(41, vector<long long>((1 << n), -1));

        for (int i = 0; i < n; i++) {
        	for (int hat : hats[i]) {
        		people[hat].push_back(i);
        	}
        }
        return dp(40, assigned, people, memo);
    }
    long long dp(int hat, int assigned, vector<vector<int>>& people, vector<vector<long long>>& memo) {
    	if (assigned == 0) return 1;
    	if (hat == 0) return 0;
    	if (memo[hat][assigned] != -1) return memo[hat][assigned];

    	long long res = dp(hat - 1, assigned, people, memo);
    	for (int p : people[hat]) {
    		if (assigned & (1 << p)) {
    			res += dp(hat - 1, assigned & ~(1 << p), people, memo);
    		}
    		res %= MOD;
    	}
    	memo[hat][assigned] = res % MOD;
    	return memo[hat][assigned];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<vector<int>> hats = {{1,2,3}, {2,3,5,6}, {1,3,7,9}, {1,8,9}, {2,5,7}};

	cout << sol.numberWays(hats) << endl;
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