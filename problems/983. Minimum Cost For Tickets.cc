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
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; ++i) {
        	int j = i;
        	while (j >= 0 && days[j] == days[i]) j--;
        	dp[i] = min(dp[i], (j >= 0 ? dp[j] : 0) + costs[0]);

        	while (j >= 0 && days[j] + 6 >= days[i]) j--;
        	dp[i] = min(dp[i], (j >= 0 ? dp[j] : 0) + costs[1]);

        	while (j >= 0 && days[j] + 29 >= days[i]) j--;
        	dp[i] = min(dp[i], (j >= 0 ? dp[j] : 0) + costs[2]);
        }
        return dp[n - 1];
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int d[] = {1,2,3,4,5,6,7,8,9,10,30,31};
	vector<int> days(d, d + 12);

	int c[] = {2,7,15};
	vector<int> costs(c, c + 3);

	cout << sol.mincostTickets(days, costs) << endl;
}