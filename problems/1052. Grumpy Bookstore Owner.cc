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
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
//         int ans = 0, n = customers.size();

//         int cur_window = 0, max_window = 0;
//         for (int i = 0; i < n; i++) {
//         	if (i < X) cur_window += customers[i] * grumpy[i];
//         	else cur_window = cur_window - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
//         	max_window = max(max_window, cur_window);
//         }

//         int satisfied = 0;
//         for (int i = 0; i < n; ++i) {
//         	satisfied += customers[i] * (grumpy[i] == 0 ? 1 : 0);
//         }
//         return satisfied + max_window;
//     }
// };

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int satisfied = 0;
        vector<int> dp(n, 0);
        dp[0] = customers[0] * grumpy[0];
        satisfied = customers[0] * (grumpy[0] == 0 ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + customers[i] * grumpy[i];
            satisfied += customers[i] * (grumpy[i] == 0 ? 1 : 0);
        }
        int maxi = 0;
        for (int i = X - 1; i < n; ++i) {
            maxi = max(maxi, dp[i] - (i - X < 0 ? 0 : dp[i - X]));
        }
        return satisfied + maxi;
    }
};


int main() {
	// Solution
	Solution sol;

	// Test cases
	int c[] = {1,0,1,2,1,1,7,5};
	vector<int> customers(c, c + 8);
	int g[] = {0,1,0,1,0,1,0,1};
	vector<int> grumpy(g, g + 8);
	int X = 3;
	cout << sol.maxSatisfied(customers, grumpy, X) << endl;

}