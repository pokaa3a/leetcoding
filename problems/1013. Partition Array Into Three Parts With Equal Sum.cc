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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        vector<int> sums(n, 0);
        for (int i = 0; i < n; ++i) {
        	sums[i] = (i == 0 ? 0 : sums[i - 1]) + A[i];
        }
        if (sums.back() % 3 != 0) return false;

        int t = sums.back() / 3;
        int x = INT_MAX, y = INT_MIN;
       	for (int i = 0; i < n; ++i) {
       		if (sums[i] == t) x = min(x, i);
       		else if (sums[i] == 2 * t) y = max(y, i);
       	}
       	if (x != INT_MAX && y != INT_MIN && y > x) return true;
       	return false; 
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}