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
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0) return -1;
        if (K % 5 == 0) return -1;

        for (int r = 0, N = 1; N <= K; ++N) {
        	r = (r * 10 + 1) % K;
        	if (r == 0) return N;
        }
        return -1;
    }
}; 

int main() {
	// Solution
	Solution sol;

	// Test cases
	cout << sol.smallestRepunitDivByK(3) << endl;

}