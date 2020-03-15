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
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
        	if (A[i] % 2 == 0) sum += A[i];
        }

        for (int i = 0; i < queries.size(); ++i) {
        	int idx = queries[i][1];
        	int val = queries[i][0];

        	int prev = A[idx];
        	A[idx] += val;
        	int next = A[idx];
        	if (prev % 2 == 0) sum -= prev;
        	if (next % 2 == 0) sum += next;
        	ans[i] = sum;
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
}