#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestMountain(vector<int> &A) {
		if (A.size() < 3) return 0;

		int ans = 0;
		int start = 0, end = 0;
		while (end < A.size()) {
			// Look for i s.t. A[i] < A[i + 1]
			for (; start < A.size() - 1; start++) {
				if (A[start] < A[start + 1]) {
					break;
				}
			}

			// Look for i s.t. A[i] > A[i + 1]
			bool flat = false;
			int peak = start + 1;
			for (; peak < A.size() - 1; peak++) {
				if (A[peak] > A[peak + 1]) {
					break;
				} else if (A[peak] == A[peak + 1]) {
					flat = true;
					start = peak + 1;
					break;
				}
			}
			if (flat) continue;

			// Look for i s.t. A[i] < A[i + 1]
			for (end = peak + 1; end < A.size(); end++) {
				if (A[end - 1] < A[end]) {
					start = end - 1;
					break;
				} else if (A[end - 1] == A[end]) {
					flat = true;
					start = end;
					break;
				}
				ans = max(ans, end - start + 1);
			}
		}
		return ans;
	}
};

int main () {
	int array[] = {2, 2, 2};
	vector<int> A(array, array + 3);

	Solution sol;
	cout << sol.longestMountain(A) << endl;
}
