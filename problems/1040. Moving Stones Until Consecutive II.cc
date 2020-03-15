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
//     vector<int> numMovesStonesII(vector<int>& stones) {
//     	sort(stones.begin(), stones.end());
//     	vector<int> ans(2, 0);
//     	int n = stones.size();
//     	int low = n, high = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);
//     	int i = 0;
//     	for (int j = 0; j < n; ++j) {
//     		while (stones[j] - stones[i] > n - 1) i++;
//     		if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
//     			low = min(low, 2);
//     		} else {
//     			low = min(low, n - (j - i + 1));
//     		}
//     	}
//     	ans[0] = low; ans[1] = high;
//     	return ans;
//     }
// };

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int low = n, high = max(stones[n - 1] - stones[1] + 1 - (n - 1), stones[n - 2] - stones[0] + 1 - (n - 1));
        int i = 0;
        for (int j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) i++;
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                low = min(low, 2);
            } else {
                low = min(low, n - (j - i + 1));
            }
        }
        vector<int> ans;
        ans.push_back(low);
        ans.push_back(high);
        return ans;
    }
};


int main() {
	// Solution
	Solution sol;

	// Test cases
	int s[] = {7,4,9};
	vector<int> stones(s, s + 3);
	vector<int> res = sol.numMovesStonesII(stones);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;

}