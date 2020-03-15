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
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int sums = 0;
        for (int i = 0; i < A.size(); ++i) {
        	if (A[i] < 0 && K > 0) {
        		sums += abs(A[i]);
        		K--;
        	} else {
        		sums += A[i];
        	}
        }
        if (K % 2 == 0) return sums;
        int found = lower_bound(A.begin(), A.end(), 0) - A.begin();
        if (found == 0) return sums - 2 * A[found];
        else return sums - 2 * min(abs(A[found]), abs(A[found - 1]));
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {2,-3,-1,5,-4};
	vector<int> A(a, a + 5);
	int K = 2;
	cout << sol.largestSumAfterKNegations(A, K) << endl;

}