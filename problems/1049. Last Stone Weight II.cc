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
    int lastStoneWeightII(vector<int>& stones) {
        bitset<1501> dp(1);

        int sum = 0;
        for (int i = 0; i < stones.size(); ++i) {
        	sum += stones[i];
        	for (int j = sum; j >= stones[i]; j--) {
        		dp[j] = dp[j] + dp[j - stones[i]];
        	}
        }

        for (int i = sum / 2; i >= 0; --i) {
        	if (dp[i]) return sum - i - i;
        }
        return 0;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int s[] = {2,7,4,1,8,1};
	vector<int> stones(s, s + 6);
	cout << sol.lastStoneWeightII(stones) << endl;
}