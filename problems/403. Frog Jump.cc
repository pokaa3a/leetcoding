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
    bool canCross(vector<int>& stones) {
    	if (stones[1] != 1) return false;

    	// define state
    	// dp[i]: set of "last jump distance" at ith stone (of course, this stone is reachable)
    	vector<unordered_set<int> > dp(stones.size(), unordered_set<int>());
    	dp[0].insert(0);
    	dp[1].insert(1);

    	for (int i = 2; i < stones.size(); ++i) {
    		for (int j = 0; j < i; ++j) {
    			long long dist = stones[i] - stones[j];
    			if (dp[j].count(dist - 1) > 0 || 
    				dp[j].count(dist) > 0 ||
    				dp[j].count(dist + 1) > 0)
    				dp[i].insert((int)dist);
    		}
    	}
    	return dp.back().size() > 0;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int s[] = {0,1,3,5,6,8,12,17};
	vector<int> stones(s, s + 8);

	cout << sol.canCross(stones) << endl;

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