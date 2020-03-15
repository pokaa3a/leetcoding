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

/* Solution */
class Solution {
public:
    int countTriplets(vector<int>& A) {
		vector<int> count((1 << 16), 0);
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < A.size(); ++j) {
				count[A[i] & A[j]]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < A.size(); ++i) {
			for (int k = 0; k < (1 << 16); ++k) {
				if ((A[i] & k) == 0) ans += count[k];
			}
		}
		return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {2,1,3};
	vector<int> A(a, a + 3);
	cout << sol.countTriplets(A) << endl;
}