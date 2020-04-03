#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int tilingRectangle(int n, int m) {
		vector<int> rect(n, 0);
		int ans = INT_MAX;
		dfs(rect, m, 0, ans);
		return ans;
	}
	void dfs(vector<int>& rect, int m, int cnt, int& ans) {
		if (cnt >= ans) return;

		int start = min_element(rect.begin(), rect.end()) - rect.begin();
		if (rect[start] == m) {
			ans = cnt;
			return;
		}
		int n = rect.size();

		int end = start;
		while (end + 1 < n && rect[end + 1] == rect[start] && ((end + 1) - start + 1) + rect[start] <= m) end++;
		for (int len = end - start + 1; len >= 1; len--) {
			for (int i = start; i <= start + len - 1; i++) rect[i] += len;
			dfs(rect, m, cnt + 1, ans);
			for (int i = start; i <= start + len - 1; i++) rect[i] -= len;
		}
	}
};

int main() {
	Solution sol;
	int n = 13, m = 13;
	cout << sol.tilingRectangle(n, m) << endl;

}