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
    int longestDecomposition(string text) {
        int n = text.size();
        int lft = 0, rht = n - 1;
        int k = 0, len = 1;
        while (lft + len - 1 < rht - len + 1) {
            string lft_str = text.substr(lft, len);
            string rht_str = text.substr(rht - len + 1, len);
            if (lft_str == rht_str) {
                k += 2;
                lft = lft + len;
                rht = rht - len;
                len = 1;
            } else {
                len++;
            }
        }
        if (rht >= lft) k++;
        return k;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string text = "aaa";
	cout << sol.longestDecomposition(text) << endl;
}