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
    int fixedPoint(vector<int>& A) {
        int ans = -1;
        for (int i = 0; i < A.size(); ++i) {
        	if (A[i] == i) {
        		ans = i;
        		return ans;
        	}
        }
        return ans;
    }
};

int main() {
  // Solution
  Solution sol;

  // Test cases

}