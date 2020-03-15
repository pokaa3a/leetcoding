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
    int bitwiseComplement(int N) {
    	if (N == 0) return 1;
    	
        int n = N, k = 0;
        while (n >> k > 0) k++;

        int x = (1 << k) - 1;
        x = ~x;
        int y = x | N;
        return ~y;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	cout << sol.bitwiseComplement(7) << endl;

}