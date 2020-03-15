#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int oddEvenJumps(vector<int>& A) {
		if (A.size() == 0) return 0;
		vector<bool> even(A.size(), false);
		vector<bool> odd(A.size(), false);
		map<int, int> store;
		
		int n = A.size();
		even[n - 1] = true;
		odd[n - 1] = true;
		store[A[n - 1]] = n - 1;

		int ans = 1;
		for (int i = n - 2; i >= 0; --i) {
			if (store.find(A[i]) != store.end()) {
				even[i] = odd[store[A[i]]];
				odd[i] = even[store[A[i]]];
			} else {
				map<int, int>::iterator j = store.upper_bound(A[i]);

				if (j != store.end()) {
					odd[i] = even[j->second];
				}
				if (j != store.begin()) {
					j--;
					even[i] = odd[j->second];
				}
			}
			store[A[i]] = i;
			ans += odd[i] ? 1 : 0;
		}
		return ans;
	}
};

int main() {
	int array[] = {5, 1, 3, 4, 2};
	vector<int> A(array, array + 5);
	Solution sol;
	cout << sol.oddEvenJumps(A) << endl;
}