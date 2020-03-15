#include <iostream>
#include <vector>
#include <map>
using namespace std;

// class Solution {
// public:
// 	int numRollsToTarget(int d, int f, int target) {
// 		vector<vector<int> > dp(d + 1, vector<int>(target + 1, 0));

// 		for (int i = 1; i <= min(f, target); ++i) {
// 			dp[1][i] = 1;
// 		}

// 		for (int i = 2; i < d; ++i) {
// 			for (int j = i; j <= min(f * i, target); ++j) {
// 				for (int k = 1; k <= min(f, j - 1); ++k) {
// 					dp[i][j] += dp[i - 1][j - k] % int(1e9 + 7);
// 					dp[i][j] = dp[i][j] % int(1e9 + 7);
// 				}
// 			}
// 		}
// 		int i = d;
// 		for (int k = 1; k <= min(f, target - 1); ++k){
// 			dp[i][target] += dp[i - 1][target - k] % int(1e9 + 7);
// 			dp[i][target] = dp[i][target] % int(1e9 + 7);
// 		}

// 		return dp[d][target];
// 	}
// };

const int MOD = 1000000007;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<long long> > dp(target + 1, vector<long long>(d + 1, 0));
        
        for (int i = 1; i <= f; ++i) {
        	if (i > target) continue;
        	dp[i][1] = 1;
        }
        
        for (int i = 2; i <= d; ++i) {
            for (int t = 1; t <= target; ++t) {
                for (int j = 1; j <= f; ++j) {
                    if (t + j > target) continue;
                    dp[t + j][i] = (dp[t + j][i] + dp[t][i - 1]) % MOD;
                }
            }
        }
        return (int)dp[target][d];
    }
};


int main() {
	int d = 30, f = 30, target = 500;
	Solution sol;
	cout << sol.numRollsToTarget(d, f, target) << endl;
}