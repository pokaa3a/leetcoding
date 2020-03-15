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
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    	int n = A.size();
    	vector<int> sums(n, 0);
    	sums[0] = A[0];
    	for (int i = 1; i < n; ++i) {
    		sums[i] = sums[i - 1] + A[i];
    	}

    	int ans = 0, L_max = 0, M_max = 0;
    	for (int i = L + M - 1; i < n; ++i) {
    		L_max = max(L_max, sums[i - M] - (i - M - L < 0 ? 0 : sums[i - M - L]));
    		M_max = max(M_max, sums[i - L] - (i - M - L < 0 ? 0 : sums[i - M - L]));

    		int L_sum = sums[i] - sums[i - L];
    		int M_sum = sums[i] - sums[i - M];
    		ans = max(ans, max(L_max + M_sum, M_max + L_sum));
    	}
    	return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {2,1,5,6,0,9,5,0,3,8};
	vector<int> A(a, a + 10);
	int L = 4, M = 3;
	cout << sol.maxSumTwoNoOverlap(A, L, M) << endl;
}