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
// class Solution {
// public:
//     vector<int> prevPermOpt1(vector<int>& A) {
//     	int n = A.size();
//     	if (n == 1) return A;

//     	for (int i = n - 2; i >= 0; --i) {
//     		if (A[i] > A[i + 1]) {
//     			int less = lower_bound(A.begin() + i + 1, A.end(), A[i]) - A.begin() - 1;
//     			while (A[less] == A[less - 1]) less--;
//     			swap(A[i], A[less]);
//     			break;
//     		}
//     	}
//     	return A;
//     }
// };

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] > A[i + 1]) {
                int less = lower_bound(A.begin() + i + 1, A.end(), A[i]) - A.begin() - 1;
                while (A[less - 1] == A[less]) less--;
                swap(A[i], A[less]);
                break;
            }
        }
        return A;
    }
};


int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {3,2,1};
	vector<int> A(a, a + 3);
	vector<int> res = sol.prevPermOpt1(A);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;
}