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
    string baseNeg2(int N) {
    	if (N == 0) return "0";
		string ans = "";

		while (N != 0) {
			if (abs(N % 2) == 1) {
				ans += "1";
				N = (N - 1) / (-2);
			} else {
				ans += "0";
				N = N / (-2);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	cout << sol.baseNeg2(3) << endl;
}