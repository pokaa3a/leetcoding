#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minSwaps(vector<int>& data) {
		int sum = 0;
		for (int i = 0; i < data.size(); ++i) {
			sum += data[i];
		}

		int cur_sum = 0;
		for (int i = 0; i < sum; ++i) {
			cur_sum += data[i];
		}

		int left = 1, right = sum, max_sum = cur_sum;
		for (; right < data.size(); left++, right++) {
			cur_sum -= data[left - 1];
			cur_sum += data[right];
			max_sum = max(cur_sum, max_sum);
		}
		return sum - max_sum;
	}
};

int main() {
	int a[] = {0};
	vector<int> data(a, a + 1);
	Solution sol;
	cout << sol.minSwaps(data) << endl;
}