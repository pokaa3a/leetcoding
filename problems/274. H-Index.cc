#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int> &citations) {
		vector<int> nums(citations.size() + 1, 0);
		int hIndex = 0;
		for (int i = 0; i < citations.size(); ++i) {
			if (citations[i] > citations.size()) {
				nums.back()++;
			} else {
				nums[citations[i]]++;
			}
		}
		int accumulate = 0;
		for (int i = citations.size(); i >= 0; --i) {
			accumulate += nums[i];
			if (accumulate >= i) {
				hIndex = i;
				break;
			}
		}
		return hIndex;
	}
};

int main() {
	int array[] = {3, 0, 6, 1 ,5};
	vector<int> citations(array, array + 5);
	Solution sol;
	cout << sol.hIndex(citations);
}