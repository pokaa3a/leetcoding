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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
// class Solution {
// public:
// 	int shipWithinDays(vector<int>& weights, int D) {
// 		int max_weight = 0, sum_weight = 0;
// 		for (int i = 0; i < weights.size(); ++i) {
// 			sum_weight += weights[i];
// 			max_weight = max(max_weight, weights[i]);
// 		}

// 		int left = max_weight, right = sum_weight;
// 		while (left < right) {
// 			int mid = (left + right) / 2;
// 			int days = countDays(weights, mid);
// 			if (days > D) {	// mid too small
// 				left = mid + 1;
// 			} else {		// mid too large
// 				right = mid;
// 			}
// 		}
// 		return right;
// 	}
// private:
// 	int countDays(vector<int>& weights, int min_weights) {
// 		int days = 0, cur_weights = 0;
// 		for (int i = 0; i < weights.size(); ++i) {
// 			cur_weights += weights[i];
// 			if (cur_weights > min_weights) {
// 				cur_weights = weights[i];
// 				days++;
// 			}
// 		}
// 		return days + 1;
// 	}
// };

class Solution {
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int n = weights.size(), max_w = 0;
		vector<int> sums(n, 0);
		for (int i = 0; i < n; ++i) {
			sums[i] = (i == 0 ? 0 : sums[i - 1]) + weights[i];
			max_w = max(max_w, weights[i]);
		}

		int left = max_w, right = sums.back();
		while (left < right) {
			int mid = (left + right) / 2;

			int d = count_days(sums, mid);
			if (d <= D) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return left;
	}

	int count_days(vector<int>& sums, int w) {
		int d = 0;
		int i = 0;
		while (i < sums.size()) {
			i = upper_bound(sums.begin() + i, sums.end(), (i == 0 ? 0 : sums[i - 1]) + w) - sums.begin();
			d++;
		}
		return d;
	}
};


int main() {
	int a[] = {1,2,3,1,1};
	vector<int> weights(a, a + 5);
	int D = 4;
	Solution sol;
	cout << sol.shipWithinDays(weights, D) << endl;
}