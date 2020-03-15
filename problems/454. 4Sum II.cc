#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
		unordered_map<int, int> sum2;	// (valud, count)
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < B.size(); ++j) {
				sum2[A[i] + B[j]]++;
			}
		}
		int count = 0;
		for (int i = 0; i < C.size(); ++i) {
			for (int j = 0; j < D.size(); ++j) {
				if (sum2.find(-C[i] - D[j]) != sum2.end()) {
					count += sum2[-C[i] - D[j]];
				}
			}
		}
		return count;
	}
};

int main () {
	int array0[] = {-1, -1};
	int array1[] = {-1, 1};
	int array2[] = {-1, 1};
	int array3[] = {1, -1};
	vector<int> A(array0, array0 + 2);
	vector<int> B(array1, array1 + 2);
	vector<int> C(array2, array2 + 2);
	vector<int> D(array3, array3 + 2);
	Solution sol;
	cout << sol.fourSumCount(A, B, C, D) << endl;
}