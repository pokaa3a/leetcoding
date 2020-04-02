#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		auto idx = lower_bound(arr.begin(), arr.end(), x);
		vector<int> ans(k, 0);
		if (idx == arr.begin()) {
			int a = 0;
			for (int i = 0; i < k; i++) {
				ans[a++] = arr[i];
			}
		} else if (idx == arr.end()) {
			int a = 0;
			for (int i = arr.size() - k; i < arr.size(); i++) {
				ans[a++] = arr[i];
			}
		} else {
			int p2 = idx - arr.begin();
			int p1 = p2 - 1;
			int idx = abs(arr[p1] - x) <= abs(arr[p2] - x) ? p1 : p2;

			int lft_cand = idx - 1, rht_cand = idx + 1, lft = idx, rht = idx;
			while (lft_cand >= 0 && rht_cand < arr.size() && (rht - lft_cand + 1 <= k || rht_cand - lft + 1 <= k)) {
				if (abs(arr[lft_cand] - x) <= abs(arr[rht_cand] - x)) {
					lft = lft_cand--;
				} else {
					rht = rht_cand++;
				}
			}
			while (lft_cand >= 0 && rht - lft_cand + 1 <= k) {
				lft = lft_cand--;
			}
			while (rht_cand < arr.size() && rht_cand - lft + 1 <= k) {
				rht = rht_cand++;
			}
			int a = 0;
			for (int i = lft; i < lft + k; i++) {
				ans[a++] = arr[i];
			}
		}
		return ans;
	}
}; 

int main() {
	vector<int> arr = {1,1,1,10,10,10};
	int k = 1, x = 9;
	Solution sol;
	vector<int> ans = sol.findClosestElements(arr, k, x);
	for (auto x : ans) cout << x << " ";
	cout << endl;
}