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
    int longestOnes(vector<int>& A, int K) {
		int lft = 0, rht = 0, k = K, n = A.size(), ans = 0;
		if (A[0] == 0) k--;
		for (;lft < n; lft++) {
			k += lft == 0 ? 0 : (A[lft - 1] == 0);
			while (k >= 0 && rht < n - 1) {
				if (A[rht + 1] == 1) rht++;
				else {
					if (k > 0) {
						rht++;
						k--;
					} else break;
				}
			}
			cout << "lft: " << lft << ", rht: " << rht << endl;
			if (k >= 0) ans = max(ans, rht - lft + 1);
		}
		return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {1,1,1,0,0,0,1,1,1,1,0};
	vector<int> A(a, a + 11);
	int K = 2;
	cout << sol.longestOnes(A, K) << endl;
}