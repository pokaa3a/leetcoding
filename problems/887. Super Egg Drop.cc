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
    int superEggDrop(int K, int N) {
        // define state:
        // dp[k][m]: max floors that we can find F (breaking floor) with
        // k eggs and m moves
        
        // transmition function:
    	// dp[k][m] = 1 + dp[k - 1][m - 1] + dp[k][m - 1]
    	// Drop first egg at 1 + dp[k - 1][m - 1] floor
    	// if the egg breaks, we can find F from 1 to dp[k - 1][m - 1] floors
    	// if not, then we can find F from (1 + dp[k - 1][m - 1]) + 1 to dp[k][m - 1] floors
    	// so the highest floor that we can find F is 1 + dp[k - 1][m - 1] + dp[k][m - 1]
        vector<vector<int> > dp(K + 1, vector<int>(N + 1, 0));

        // initialize state
        for (int m = 1; m <= N; ++m) {
        	dp[1][m] = m;
        }
        for (int k = 2; k <= K; ++k) {
        	for (int m = 1; m <= N; ++m) {
        		dp[k][m] = 1 + dp[k - 1][m - 1] + dp[k][m - 1];
        		if (dp[k][m] > N) break;
        	}
        }
        for (int m = 0; m <= N; ++m) {
        	if (dp[K][m] >= N) return m;
        }
        return N;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int K = 10, N = 100;
	cout << sol.superEggDrop(K, N) << endl;

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