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

const int MOD = 1000000007;

/* Solution */
// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& A, int K) {
//         int n = A.size();
//         vector<int> dp(n + 1, 0);

//         for (int i = 1; i < n + 1; ++i) {
//         	int cur_max = 0;
//         	for (int k = 1; k <= K && i - k >= 0; k++) {
//         		cur_max = max(cur_max, A[i - k]);
//         		dp[i] = max(dp[i], dp[i - k] + cur_max * k);
//         	}
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            int cur_max = A[i];
            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
                cur_max = max(cur_max, A[i - k + 1]);
                dp[i] = max(dp[i], cur_max * k + (i - k < 0 ? 0 : dp[i - k]));

            }
            cout << "dp[" << i << "]: " << dp[i] << endl;
        }
        return dp[n - 1];
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {1,15,7,9,2,5,10};
	vector<int> A(a, a + 7);
	int K = 3;
	cout << sol.maxSumAfterPartitioning(A, K);
}