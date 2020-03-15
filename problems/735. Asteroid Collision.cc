#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int> &asteroids) {
		stack<int> st;

		for (int i = 0; i < asteroids.size(); ++i) {
			if (asteroids[i] < 0) {
				// destroy all positive asteroid s.t. smaller than asteroids[i]
				while (!st.empty() && st.top() > 0 && abs(st.top()) < abs(asteroids[i])) {
					st.pop();
				}
				if (st.empty() || st.top() < 0) {
					st.push(asteroids[i]);
				} else if (abs(st.top()) == abs(asteroids[i])) {
					st.pop();
				}
			} else {
				st.push(asteroids[i]);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	int array[] = {-2, -1, 1, 2};
	vector<int> asteroids(array, array + 4);

	Solution sol;
	vector<int> res = sol.asteroidCollision(asteroids);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
}