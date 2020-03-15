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
private:
	map<long long, long long> dp;
public:
    int leastOpsExpressTarget(int x, int target) {
    	return (int)least(x, target);
    }
    long long least(long long x, long long target) {
    	cout << "target = " << target << endl;
    	if (dp.find(target) != dp.end()) return dp[target];
    	if (target == x) return 0;

    	long long a1, a2;
    	int k = 0;
    	while (1) {
    		if (pow(x, k) <= target && target < pow(x, k + 1)) break;
    		k++;
    	}
    	if (k == 0) {
    		if (target <= 1) return target;
    		a1 = 2 * target - 1;
    		a2 = 2 * (x - target);
    		return min(a1, a2);
    	}

    	long long remain = pow(x, k + 1) - target;

    	a1 = (target / pow(x, k)) * k - 1;
    	if (remain < pow(x, k)) {
    		a2 = k;
    	} else {
    		a2 = k + 1 + (remain / pow(x, k)) * k - 1;
    	}

    	if (target % (int)pow(x, k) != 0) {
    		a1 += 1 + least(x, target % (int)pow(x, k));
    	}
    	if (remain % (int)pow(x, k) != 0) {
    		a2 += 1 + least(x, remain % (int)pow(x, k));
    	}
    	dp[target] = min(a1, a2);
    	return min(a1, a2);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int x = 3, target = 122;
	cout << sol.leastOpsExpressTarget(x, target) << endl;
	// cout << target % (int)pow(x, 3) << endl;

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