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
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int r = 0;
        vector<bool> ans(A.size(), false);
        for (int i = 0; i < A.size(); ++i) {
        	r = (r * 2 + A[i]) % 5;
        	if (r == 0) ans[i] = true;
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}