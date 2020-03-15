#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct comp {
	bool operator() (const int& a, const int& b) {
		return a > b;
	}
};

class Solution {
public:
	int connectSticks(vector<int>& sticks) {
		priority_queue<int, vector<int>, greater<int> > pq(sticks.begin(), sticks.end());
		// for (int i = 0; i < sticks.size(); ++i) {
		// 	pq.push(sticks[i]);
		// }
		int res = 0;
		while (pq.size() > 1) {
			int s1 = pq.top();
			pq.pop();
			int s2 = pq.top();
			pq.pop();
			res += s1 + s2;
			pq.push(s1 + s2);
		}
		return res;
	}
};

int main() {
	int s[] = {1, 8, 3, 5};
	vector<int> sticks(s, s + 4);
	Solution sol;
	cout << sol.connectSticks(sticks) << endl;
}