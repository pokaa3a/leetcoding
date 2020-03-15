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
    int heightChecker(vector<int>& heights) {
        vector<int> correct = heights;
        sort(correct.begin(), correct.end());

        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
        	ans += heights[i] == correct[i] ? 0 : 1;
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}