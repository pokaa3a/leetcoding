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
    int tribonacci(int n) {
        vector<long long> T(max(n + 1, 4), 0);
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;
        T[3] = 2;
        for (int i = 4; i <= n; ++i) {
            T[i] = 2 * T[i - 1] - T[i - 4];
        }
        return (int)T[n];
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}