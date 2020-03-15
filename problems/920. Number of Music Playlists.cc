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
	vector<int> fact;
public:
    int numMusicPlaylists(int N, int L, int K) {
        // define state:
        // dp[i][j]: number of i songs and list length j
        // dp[i][j] = dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - k)
        // (1) dp[i - 1][j - 1] * i: there are only (i - 1) songs, the last song must 
        // 							 be the rest one, and there are i options
        // (2) dp[i][j - 1] * (i - k): there are i songs in length (j - 1), the last song
        // 							   cannot be the last k songs
        vector<vector<long long> > dp(N + 1, vector<long long>(L + 1, 0));
        dp[K][K] = factorial(K);
        for (int i = K + 1; i <= N; ++i) {
        	for (int j = i; j <= L; ++j) {
        		// if (i == j) dp[i][j] = factorial(i);
        		// else {
        			dp[i][j] = (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K)) % MOD;
        		// }
        	}
        }
        return dp[N][L];
    }
  
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int N = 2, L = 3, K = 1;
	cout << sol.numMusicPlaylists(N, L, K) << endl;

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