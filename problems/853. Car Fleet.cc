#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
	int carFleet(int target, vector<int>& position, 
		vector<int>& speed) {
		map<int, double> m;
		for (int i = 0; i < position.size(); ++i) {
			// ceil(target / speed[i])
			m[position[i]] = (double)(target - position[i]) / (double)speed[i];
		}

		stack<double> st;
		for (map<int, double>::iterator it = m.begin(); it != m.end(); ++it) {
			double t = it->second;
			while (!st.empty() && st.top() <= t) {
				st.pop();
			}
			st.push(t);
		}
		return st.size();
	}
};

int main() {
	int target = 10;
	int position_array[] = {8, 3, 7, 4, 6, 5};
	int speed_array[] = {4, 4, 4, 4, 4, 4};
	vector<int> position(position_array, position_array + 6);
	vector<int> speed(speed_array, speed_array + 6);
	Solution sol;
	cout << sol.carFleet(target, position, speed) << endl;
}