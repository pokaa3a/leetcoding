#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	int assignBikes(vector<vector<int> >& workers, vector<vector<int> >& bikes) {
		int left_bikes = 0;
		for (int i = 0; i < bikes.size(); ++i) {
			left_bikes = (left_bikes << 1) | 1;
		}

		map<pair<int, int>, int> dp;
		return toAssign(0, left_bikes, dp, workers, bikes);
	}
	int toAssign(int cur_worker, int left_bikes, map<pair<int, int>, int>& dp, 
				 vector<vector<int> >& workers, vector<vector<int> >& bikes) {
		int num_bikes = bikes.size(), num_workers = workers.size();
		map<pair<int, int>, int>::iterator it = dp.find(make_pair(cur_worker, left_bikes));
		if (it != dp.end()) {
			return it->second;
		}
		if (cur_worker == num_workers) return 0;

		int shortest = INT_MAX;
		for (int i = 0; i < num_bikes; ++i) {
			if (left_bikes & (1 << i)) {
				left_bikes &= ~(1 << i);
				int dist = abs(workers[cur_worker][0] - bikes[i][0]) + abs(workers[cur_worker][1] - bikes[i][1]);
				shortest = min(shortest, dist + toAssign(cur_worker + 1, left_bikes, dp, workers, bikes));
				left_bikes |= (1 << i);
			}
		}
		dp[make_pair(cur_worker, left_bikes)] = shortest;
		return shortest;
	}
};

int main() {
	vector<vector<int> > workers;
	vector<vector<int> > bikes;

	int worker0[] = {0, 0};
	int worker1[] = {1, 1};
	int worker2[] = {2, 0};
	int bike0[] = {1, 0};
	int bike1[] = {2, 2};
	int bike2[] = {2, 1};

	workers.push_back(vector<int>(worker0, worker0 + 2));
	workers.push_back(vector<int>(worker1, worker1 + 2));
	workers.push_back(vector<int>(worker2, worker2 + 2));
	bikes.push_back(vector<int>(bike0, bike0 + 2));
	bikes.push_back(vector<int>(bike1, bike1 + 2));
	bikes.push_back(vector<int>(bike2, bike2 + 2));
	Solution sol;
	cout << sol.assignBikes(workers, bikes) << endl;
}