#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		if (n == INT_MAX) return 32;
		queue<int> q;
		q.push(n);
		int res = 0;

		while (!q.empty()) {
			int k = q.size();
			for (int i = 0; i < k; ++i) {
				int x = q.front();
				q.pop();
				if (x == 1) return res;
				if (x % 2 == 0) {
					q.push(x / 2);
				} else {
					q.push(x + 1);
					q.push(x - 1);
				}
			}
			res++;
		}
		return res;
	}
};

int main () {
	Solution sol;
	cout << sol.integerReplacement(8) << endl;
}