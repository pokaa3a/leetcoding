#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int largestUniqueNumber(vector<int>& A) {
		map<int, int> mp;
		for (int i = 0; i < A.size(); ++i) {
			mp[A[i]]++;
		}
		for (map<int, int>::iterator it = mp.end(); it != mp.begin();) {
			--it;
			if (it->second == 1) return it->first;
		}
		return -1;
	}
};

int main() {
	int a[] = {5,7,3,9,4,9,8,3,1};
	vector<int> A(a, a + 9);
	Solution sol;
	cout << sol.largestUniqueNumber(A) << endl;
}