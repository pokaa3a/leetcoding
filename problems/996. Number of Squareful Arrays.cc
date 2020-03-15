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
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        vector<vector<int> > dp((1 << n), vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
        	dp[(1 << i)][i] = 1;
        }

        for (int mask = 0; mask < (1 << n); ++mask) {
        	for (int i = 0; i < n; ++i) {
        		if (dp[mask][i] == 0) continue;
        		// cout << "mask: " << mask << endl;
        		for (int j = 0; j < n; ++j) {
        			if ((mask & (1 << j)) == 0) {
	        			// cout << "i: " << i << " j: " << j << endl;
	        			if (isSquareful(A[i] + A[j])) {
	        				// cout << "square" << endl;
	        				dp[mask | (1 << j)][j] += dp[mask][i];
	        			}
        			}
        		}
        	}
        }
        long long total = 0;
        for (int i = 0; i < n; ++i) {
        	total += dp[(1 << n) - 1][i];
        }

        sort(A.begin(), A.end());

        for (int i = 0; i < n;) {
        	int j = i;
        	while (j < n && A[i] == A[j]) {
        		total /= j - i + 1;
        		j++;
        	}
        	i = j;
        }
        return (int)total;
    }

    bool isSquareful(int x) {
    	int s = sqrt(x + 0.0);
    	return s * s == x;
    }
};


int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {1, 17, 8};
	vector<int> A(a, a + 3);
	cout << sol.numSquarefulPerms(A) << endl;

}