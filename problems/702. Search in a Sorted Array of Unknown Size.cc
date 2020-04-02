#include <iostream>
#include <vector>
using namespace std;

class ArrayReader {
public:
	vector<int> A;
	ArrayReader(vector<int> a) {
		A = a;
	}
	int get(int index) const {
		if (index >= A.size()) return INT_MAX;
		return A[index];
	}
};

class Solution {
public:
	int search(const ArrayReader& reader, int target) {
		int max_size = 19999;
		// first search for the size
		int lo = 0, hi = max_size - 1;
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			if (reader.get(mi) != INT_MAX) {
				lo = mi + 1;
			} else {
				hi = mi;
			}
		}
		int len = lo;

		lo = 0, hi = len - 1;
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			if (reader.get(mi) == target) return mi;
			else if (reader.get(mi) < target) {
				lo = mi + 1;
			} else {	// reader.get(mi) > target
				hi = mi - 1;
			}
		}
		return reader.get(lo) == target ? lo : -1;
	}
};

int main() {
	ArrayReader reader(vector<int>{5});
	Solution sol;
	int target = 5;
	cout << sol.search(reader, target) << endl;

}