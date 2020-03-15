#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int> &citations) {
		int n = citations.size();
		int left = 0, right = citations.size() - 1, mid;
		while (right >= left) {
			mid = (left + right) / 2;
			if (citations[mid] == (n - mid)) return n - mid;
			else if (citations[mid] > (n - mid)) right = mid - 1;
			else left = mid + 1;
		}
		return n - (right + 1);
	}
};

int main() {
	int array[] = {0};
	vector<int> citations(array, array + 1);
	Solution sol;
	cout << sol.hIndex(citations);
}