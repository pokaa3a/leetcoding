#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int twoSumLessThanK(vector<int>& A, int K) {
		sort(A.begin(), A.end());

		int res = -1;
		for (int i = 0; i < A.size() - 1; ++i) {
			int j = i + 1;
			if (A[i] + A[j] >= K) break;
			res = max(res, A[i] + b_search(K - A[i] - 1, i + 1, A.size() - 1, A));
		}
		return res;
	}
	
	// search for largest i s.t. A[i] <= target
	int b_search(int target, int left, int right, vector<int>& A) {
		while (left < right) {
			int mid = (left + right + 1) / 2;
			if (A[mid] <= target) {
				left = mid;
			} else {
				right = mid - 1;
			}
		}
		return A[left];
	}

	/*
	int twoSumLessThanK(vector<int>& A, int K) {
		int res = -1;
		for (int i = 0; i < A.size() - 1; ++i) {
			for (int j = i + 1; j < A.size(); ++j) {
				int s = A[i] + A[j];
				res = s < K ? max(res, s) : res;
			}
		}
		return res;
	}
	*/
};

int main() {
	int a[] = {34,23,1,24,75,33,54,8};
	vector<int> A(a, a + 8);
	int K = 60;
	Solution sol;
	cout << sol.twoSumLessThanK(A, K) << endl;
}