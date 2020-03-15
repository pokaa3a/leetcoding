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
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size(), ans = 0;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) sums[i] = sums[i - 1] + calories[i - 1];

        for (int i = k; i < n + 1; ++i) {
        	int consume = sums[i] - sums[i - k];
        	if (consume < lower) ans--;
        	if (consume > upper) ans++;
        }
        return ans;
    }
};

int main() {
  // Solution
  Solution sol;

  // Test cases
  int c[] = {6,5,0,0};
  vector<int> calories(c, c + 4);
  int k = 2, lower = 1, upper = 5;

  cout << sol.dietPlanPerformance(calories, k, lower, upper) << endl;
}