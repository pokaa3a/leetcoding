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
    vector<int> beautifulArray(int N) {
        // IDEA: if array A is beautiful, then
        // array [2 * A, 2 * A - 1] is also beautiful
        // -> divid and conquer into two sub problems
    	return helper(N, N);
    }

    vector<int> helper(int sz, int N) {
    	if (sz == 1) return vector<int>(1, 1);

    	sz = sz % 2 == 0 ? sz / 2 : (sz + 1) / 2;
    	vector<int> A = helper(sz, N);

    	int n = A.size();
    	vector<int> res;
    	for (int i = 0; i < n; ++i) {
    		if (2 * A[i] <= N) res.push_back(2 * A[i]);
    	}
    	for (int i = 0; i < n; ++i) {
    		if (2 * A[i] - 1 <= N) res.push_back(2 * A[i] - 1);
    	}
    	return res;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int N = 4;
	vector<int> ans = sol.beautifulArray(N);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl;

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